################################################################################
# Generig Makefile for SAML11!
#  Configured for non-secure
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

FREERTOS_ROOT=../../../..

# List the subdirectories for creating object files
SUB_DIRS += hpl/pm 
SUB_DIRS += gcc
SUB_DIRS += hpl/osc32kctrl
SUB_DIRS += hpl/dmac
SUB_DIRS += hal/src
SUB_DIRS += hpl/mclk
SUB_DIRS += hal/utils/src
SUB_DIRS += examples
SUB_DIRS += hpl/gclk
SUB_DIRS += hpl/oscctrl
SUB_DIRS += gcc/gcc
SUB_DIRS += hpl/core
SUB_DIRS += $(FREERTOS_ROOT)/Source
SUB_DIRS += ParTest

# List the object files
OBJS += examples/driver_examples.o
OBJS += gcc/gcc/startup_saml11e16a.o
OBJS += gcc/system_saml11e16a.o
OBJS += hal/src/hal_io.o
OBJS += hal/src/hal_delay.o
OBJS += hal/src/hal_gpio.o
OBJS += hal/src/hal_sleep.o
OBJS += hal/src/hal_init.o
OBJS += hal/utils/src/utils_list.o
OBJS += hal/utils/src/utils_assert.o
OBJS += hal/utils/src/utils_event.o
OBJS += hal/utils/src/utils_syscalls.o
OBJS += hal/src/hal_atomic.o
OBJS += hpl/core/hpl_init.o
OBJS += hpl/core/hpl_core_m23_base.o
OBJS += hpl/dmac/hpl_dmac.o
OBJS += hpl/gclk/hpl_gclk.o
OBJS += hpl/mclk/hpl_mclk.o
OBJS += hpl/oscctrl/hpl_oscctrl.o
OBJS += hpl/osc32kctrl/hpl_osc32kctrl.o
OBJS += hpl/pm/hpl_pm.o
OBJS += $(FREERTOS_ROOT)/Source/tasks.o
OBJS += $(FREERTOS_ROOT)/Source/queue.o
OBJS += $(FREERTOS_ROOT)/Source/list.o
OBJS += $(FREERTOS_ROOT)/Source/timers.o
#0BJS += $(FREERTOS_ROOT)/Source/event_groups.o
#0BJS += $(FREERTOS_ROOT)/Source/croutine.o
OBJS += $(FREERTOS_ROOT)/Source/portable/MemMang/heap_1.o
OBJS += $(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11/port.o
OBJS += ParTest/ParTest.o
OBJS += driver_init.o
OBJS += atmel_start.o
OBJS += main.o
OBJS += main-blinky.o



OBJS_AS_ARGS := $(OBJS:%= "%")

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS := $(DEPS:%="%")


OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target

LDFLAGS += -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS) -Wl,--start-group -lm -l:libsecure_gateway_veneer.lib -Wl,--end-group -mthumb
LDFLAGS += -Wl,-Map="$(OUTPUT_FILE_NAME).map" --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base
LDFLAGS += -T"gcc/gcc/saml11_nonsecure.ld"
LDFLAGS += -L"gcc/gcc"

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(LDFLAGS)
	@echo Finished building target: $@

	"arm-none-eabi-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"arm-none-eabi-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" -R .userRowBlock "$(OUTPUT_FILE_NAME)s.bin"
	"arm-none-eabi-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"arm-none-eabi-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"arm-none-eabi-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"arm-none-eabi-size" "$(OUTPUT_FILE_NAME).elf"

	@echo Note:
	@echo ============== IMPORTANT NOTE for SAML11 Non-Secure Project ============================
	@echo The SAML11 Non-Secure Project needs input files from secure project. Here are the example steps:
	@echo 1. Get Device_Startup/saml11_nonsecure.ld, trustzone/trustzone_veneer.h and gcc/libsecure_gateway_veneer.lib files from secure project
	@echo 2. Copy saml11_nonsecure.ld into gcc/gcc folder in non-secure project
	@echo 3. Copy trustzone_veneer.h and libsecure_gateway_veneer.lib into root folder in non-secure project
	@echo 4. Update Makefile to use new linker script: -T"../gcc/gcc/saml11_nonsecure.ld"
	@echo 5. Update Makefile to inlcude secure gateway lib: -Wl,--start-group -lm -l:libsecure_gateway_veneer.lib -L"../" -Wl,--end-group
	@echo ========================================================================================

# Compiler targets

CLIB_DIRS := $(SUB_DIRS:%= -I"%")
CLIB_DIRS += -I"."
CLIB_DIRS += -I"CMSIS/Include"
CLIB_DIRS += -I"include"
CLIB_DIRS += -I"config"
CLIB_DIRS += -I"examples"
CLIB_DIRS += -I"hal/include"
CLIB_DIRS += -I"hal/utils/include"
CLIB_DIRS += -I"hpl/core"
CLIB_DIRS += -I"hpl/crya"
CLIB_DIRS += -I"hpl/dmac"
CLIB_DIRS += -I"hpl/gclk"
CLIB_DIRS += -I"hpl/mclk"
CLIB_DIRS += -I"hpl/osc32kctrl"
CLIB_DIRS += -I"hpl/oscctrl"
CLIB_DIRS += -I"hpl/pm"
CLIB_DIRS += -I"hpl/port"
CLIB_DIRS += -I"hri"
CLIB_DIRS += -I$(QUOTE)$(FREERTOS_ROOT)/Demo/Common$(QUOTE) 
CLIB_DIRS += -I$(QUOTE)$(FREERTOS_ROOT)/Source/include$(QUOTE) 
CLIB_DIRS += -I$(QUOTE)$(FREERTOS_ROOT)/Demo/MICROCHIP_ATSAML11E16A_GCC$(QUOTE) 
CLIB_DIRS += -I$(QUOTE)$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11$(QUOTE) 


CFLAGS += -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99
CFLAGS += -D__SAML11E16A__ -march=armv8-m.base -DFREERTOS_NVIC_NONSECURE
CFLAGS += $(CLIB_DIRS)
CFLAGS += -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"

%.o: %.c
	@echo Building file: $<
	@echo ARM/GNU C Compiler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(CFLAGS) -o "$@" "$<"
	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARM/GNU Assembler
	$(QUOTE)arm-none-eabi-as$(QUOTE) $(CFLAGS) -o "$@" "$<"
	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARM/GNU Preprocessing Assembler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(CFLAGS) -o "$@" "$<"
	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

load:
	edbg -t mchp_cm23 -p -o 0xC000 -f AtmelStarts.bin

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
