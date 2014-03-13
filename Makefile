PROJECT=main

OUTDIR = build/
OBJDIR = $(OUTDIR)obj/
LSTDIR = $(OUTDIR)lst/

include lib/lib.mk
include audioLights/al.mk

SRCS = $(ALSRC) $(LIBSRC) 
INCS = $(ALINC) $(LIBINC)
ASSRCS = $(LIBAS)

TARGET = arm-none-eabi-
CC = $(TARGET)gcc
LD = $(TARGET)gcc
AS = $(TARGET)gcc -x assembler-with-cpp
OD = $(TARGET)objdump
CP = $(TARGET)objcopy
SZ = $(TARGET)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary

CFLAGS  = -g3 -O0 -Wall -Wextra -mlittle-endian -mthumb
CFLAGS += -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# CFLAGS += -MD -MP -MF .dep/$(@F).d
# CFLAGS += -Wa,-alms=$(LSTDIR)/$(notdir $(<:.c=.lst))

ASFLAGS = -mcpu=cortex-m4 -mthumb -mthumb-interwork

LDFLAGS = -mcpu=cortex-m4 -nostartfiles -T$(LDSCRIPT)
LDFLAGS += -Wl,-Map=$(OUTDIR)/$(PROJECT).map,--cref,--no-warn-mismatch,--gc-sections
LDFLAGS += -mthumb-interwork -mthumb 

OBJS = 	$(addprefix $(OBJDIR),$(notdir $(SRCS:.c=.o)) $(notdir $(ASSRCS:.s=.o)))

OUTFILES = 	$(OUTDIR)$(PROJECT).elf $(OUTDIR)$(PROJECT).hex \
			$(OUTDIR)$(PROJECT).bin $(OUTDIR)$(PROJECT).dmp

IINC = $(patsubst %,-I% ,$(INCS))

SRCPATHS = $(sort $(dir $(SRCS)) $(dir $(ASSRCS)))

VPATH = $(SRCPATHS)

all: $(OBJS) $(OUTFILES) size

size: $(OUTFILES)
	@$(SZ) $(OUTDIR)$(PROJECT).hex $(OUTDIR)$(PROJECT).elf

$(OBJS): | buildDir

$(OBJDIR)%.o: %.c Makefile
	@echo Compiling $<
	@$(CC) -c $(CFLAGS) $(IINC) $< -o $@

$(OBJDIR)%.o: %.s Makefile
	@echo Compiling $<
	@$(AS) -c $(ASFLAGS) $(IINC) $< -o $@

%.elf: $(OBJS) $(LDSCRIPT)
	@echo Linking $@
	@$(LD) $(OBJS) $(LDFLAGS) -o $@

%.hex: %.elf $(OBJS) $(LDSCRIPT)
	@echo Creating $@
	@$(HEX) $< $@

%.bin: %.elf $(OBJS) $(LDSCRIPT)
	@echo Creating $@
	@$(BIN) $< $@

%.dmp: %.elf $(LDSCRIPT)
	@echo Creating $@
	@$(OD) -x --syms $< > $@

buildDir:
	@mkdir -p $(OUTDIR)
	@mkdir -p $(OBJDIR)
#	@mkdir -p $(LSTDIR)

clean: 
	@echo Cleaning...
	rm -rf $(OUTDIR) .dep
	@echo Done

# include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)