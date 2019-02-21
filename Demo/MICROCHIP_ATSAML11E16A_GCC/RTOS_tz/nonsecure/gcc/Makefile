################################################################################
# Automatically-generated file. Do not edit!
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

# List the object files
OBJS += hal/src/hal_io.o
OBJS += gcc/gcc/startup_saml11e16a.o
OBJS += gcc/system_saml11e16a.o
OBJS += hal/utils/src/utils_syscalls.o
OBJS += hal/src/hal_delay.o
OBJS += hpl/oscctrl/hpl_oscctrl.o
OBJS += hpl/core/hpl_init.o
OBJS += hal/utils/src/utils_list.o
OBJS += hal/utils/src/utils_assert.o
OBJS += hpl/dmac/hpl_dmac.o
OBJS += hpl/pm/hpl_pm.o
OBJS += hpl/mclk/hpl_mclk.o
OBJS += hpl/gclk/hpl_gclk.o
OBJS += hal/src/hal_init.o
OBJS += main.o
OBJS += hpl/osc32kctrl/hpl_osc32kctrl.o
OBJS += examples/driver_examples.o
OBJS += driver_init.o
OBJS += hpl/core/hpl_core_m23_base.o
OBJS += hal/src/hal_gpio.o
OBJS += hal/utils/src/utils_event.o
OBJS += hal/src/hal_sleep.o
OBJS += atmel_start.o
OBJS += hal/src/hal_atomic.o

OBJS_AS_ARGS += "hal/src/hal_io.o"
OBJS_AS_ARGS += "gcc/gcc/startup_saml11e16a.o"
OBJS_AS_ARGS += "gcc/system_saml11e16a.o"
OBJS_AS_ARGS += "hal/utils/src/utils_syscalls.o"
OBJS_AS_ARGS += "hal/src/hal_delay.o"
OBJS_AS_ARGS += "hpl/oscctrl/hpl_oscctrl.o"
OBJS_AS_ARGS += "hpl/core/hpl_init.o"
OBJS_AS_ARGS += "hal/utils/src/utils_list.o"
OBJS_AS_ARGS += "hal/utils/src/utils_assert.o"
OBJS_AS_ARGS += "hpl/dmac/hpl_dmac.o"
OBJS_AS_ARGS += "hpl/pm/hpl_pm.o"
OBJS_AS_ARGS += "hpl/mclk/hpl_mclk.o"
OBJS_AS_ARGS += "hpl/gclk/hpl_gclk.o"
OBJS_AS_ARGS += "hal/src/hal_init.o"
OBJS_AS_ARGS += "main.o"
OBJS_AS_ARGS += "hpl/osc32kctrl/hpl_osc32kctrl.o"
OBJS_AS_ARGS += "examples/driver_examples.o"
OBJS_AS_ARGS += "driver_init.o"
OBJS_AS_ARGS += "hpl/core/hpl_core_m23_base.o"
OBJS_AS_ARGS += "hal/src/hal_gpio.o"
OBJS_AS_ARGS += "hal/utils/src/utils_event.o"
OBJS_AS_ARGS += "hal/src/hal_sleep.o"
OBJS_AS_ARGS += "atmel_start.o"
OBJS_AS_ARGS += "hal/src/hal_atomic.o"


# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS += "gcc/system_saml11e16a.d"
DEPS_AS_ARGS += "gcc/gcc/startup_saml11e16a.d"
DEPS_AS_ARGS += "hal/src/hal_gpio.d"
DEPS_AS_ARGS += "hal/src/hal_io.d"
DEPS_AS_ARGS += "hal/utils/src/utils_syscalls.d"
DEPS_AS_ARGS += "hal/utils/src/utils_list.d"
DEPS_AS_ARGS += "hpl/dmac/hpl_dmac.d"
DEPS_AS_ARGS += "hal/utils/src/utils_assert.d"
DEPS_AS_ARGS += "hal/src/hal_delay.d"
DEPS_AS_ARGS += "hpl/core/hpl_init.d"
DEPS_AS_ARGS += "hpl/pm/hpl_pm.d"
DEPS_AS_ARGS += "hpl/gclk/hpl_gclk.d"
DEPS_AS_ARGS += "hal/src/hal_init.d"
DEPS_AS_ARGS += "hpl/mclk/hpl_mclk.d"
DEPS_AS_ARGS += "driver_init.d"
DEPS_AS_ARGS += "hpl/osc32kctrl/hpl_osc32kctrl.d"
DEPS_AS_ARGS += "main.d"
DEPS_AS_ARGS += "examples/driver_examples.d"
DEPS_AS_ARGS += "hal/src/hal_sleep.d"
DEPS_AS_ARGS += "hpl/core/hpl_core_m23_base.d"
DEPS_AS_ARGS += "hal/utils/src/utils_event.d"
DEPS_AS_ARGS += "hal/src/hal_atomic.d"
DEPS_AS_ARGS += "hpl/oscctrl/hpl_oscctrl.d"
DEPS_AS_ARGS += "atmel_start.d"


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

LDFLAGS += -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS) -Wl,--start-group -lm -l:libsecure_gateway_veneer.lib -L"../" -Wl,--end-group -mthumb
LDFLAGS += -Wl,-Map="$(OUTPUT_FILE_NAME).map" --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base
LDFLAGS += -T"../gcc/gcc/saml11_nonsecure.ld"
LDFLAGS += -L"../gcc/gcc"

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(LDFLAGS)
	@echo Finished building target: $@

	"arm-none-eabi-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
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

CLIB_DIRS += -I"../"
CLIB_DIRS += -I"../CMSIS/Include"
CLIB_DIRS += -I"../include"
CLIB_DIRS += -I"../config"
CLIB_DIRS += -I"../examples"
CLIB_DIRS += -I"../hal/include"
CLIB_DIRS += -I"../hal/utils/include"
CLIB_DIRS += -I"../hpl/core"
CLIB_DIRS += -I"../hpl/crya"
CLIB_DIRS += -I"../hpl/dmac"
CLIB_DIRS += -I"../hpl/gclk"
CLIB_DIRS += -I"../hpl/mclk"
CLIB_DIRS += -I"../hpl/osc32kctrl"
CLIB_DIRS += -I"../hpl/oscctrl"
CLIB_DIRS += -I"../hpl/pm"
CLIB_DIRS += -I"../hpl/port"
CLIB_DIRS += -I"../hri"

CFLAGS += -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99
CFLAGS += -D__SAML11E16A__ -march=armv8-m.base
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

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
