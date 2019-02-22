################################################################################
# Generic Makefile for SAML11!
#  Set for secure build of freeRTOS
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
SUB_DIRS += examples
SUB_DIRS += hpl/oscctrl
SUB_DIRS += stdio_redirect/gcc
SUB_DIRS += gcc
SUB_DIRS += hpl/osc32kctrl
SUB_DIRS += trustzone
SUB_DIRS += hpl/dmac
SUB_DIRS += hal/src
SUB_DIRS += stdio_redirect
SUB_DIRS += hal/utils/src
SUB_DIRS += hpl/wdt
SUB_DIRS += hpl/rtc
SUB_DIRS += hpl/pm
SUB_DIRS += hpl/gclk
SUB_DIRS += gcc/gcc
SUB_DIRS += hpl/tram
SUB_DIRS += hpl/mclk
SUB_DIRS += Secure_Functions
SUB_DIRS += hpl/pac
SUB_DIRS += hpl/sercom
SUB_DIRS += temperature_sensor
SUB_DIRS += hpl/nvmctrl
SUB_DIRS += hpl/core

# List the object files
OBJS += gcc/system_saml11e16a.o 
OBJS += gcc/gcc/startup_saml11e16a.o 
OBJS += hal/src/hal_pac.o 
OBJS += hal/src/hal_i2c_m_sync.o 
OBJS += hal/src/hal_io.o 
OBJS += hal/src/hal_delay.o 
OBJS += hal/src/hal_wdt.o 
OBJS += hal/src/hal_usart_sync.o 
OBJS += hal/src/hal_init.o 
OBJS += hal/src/hal_gpio.o 
OBJS += hal/src/hal_sleep.o 
OBJS += hal/src/hal_atomic.o
OBJS += hal/utils/src/utils_list.o 
OBJS += hal/utils/src/utils_syscalls.o 
OBJS += hal/utils/src/utils_assert.o 
OBJS += hal/utils/src/utils_event.o 
OBJS += hpl/core/hpl_init.o 
OBJS += hpl/core/hpl_core_m23_base.o 
OBJS += hpl/dmac/hpl_dmac.o 
OBJS += hpl/gclk/hpl_gclk.o 
OBJS += hpl/mclk/hpl_mclk.o 
OBJS += hpl/nvmctrl/nvmctrl_lite.o 
OBJS += hpl/oscctrl/hpl_oscctrl.o 
OBJS += hpl/osc32kctrl/hpl_osc32kctrl.o 
OBJS += hpl/pac/hpl_pac.o 
OBJS += hpl/pm/hpl_pm.o 
OBJS += hpl/rtc/rtc_lite.o 
OBJS += hpl/sercom/hpl_sercom.o 
OBJS += hpl/tram/tram_lite.o 
OBJS += hpl/wdt/hpl_wdt.o 
OBJS += Secure_Functions/secure_tram.o 
OBJS += Secure_Functions/secure_led.o 
OBJS += Secure_Functions/secure_wdt.o 
OBJS += Secure_Functions/secure_lowpower.o 
OBJS += Secure_Functions/secure_dataflash.o 
OBJS += Secure_Functions/secure_pac.o 
OBJS += Secure_Functions/secure_rtc.o 
OBJS += stdio_redirect/stdio_io.o 
OBJS += stdio_redirect/gcc/read.o 
OBJS += stdio_redirect/gcc/write.o 
OBJS += trustzone/trustzone_manager.o 
OBJS += trustzone/trustzone_veneer.o 
OBJS += examples/driver_examples.o 
OBJS += app_veneer.o 
OBJS += stdio_start.o 
OBJS += main.o 
OBJS += atmel_start.o 
OBJS += driver_init.o 

OBJS_AS_ARGS := $(OBJS:%= "%")

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS := $(DEPS:%= "%")

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

SECLIB_NAME =libsecure_gateway_veneer.lib

LDFLAGS += -Wl,--start-group -lm -Wl,--end-group -mthumb
LDFLAGS += -Wl,-Map="$(OUTPUT_FILE_NAME).map" --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base
LDFLAGS += -Wl,--out-implib=$(SECLIB_NAME) -Wl,--cmse-implib
LDFLAGS += -T"../Device_Startup/saml11_secure.ld"
LDFLAGS += -L"../Device_Startup"

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS) $(LDFLAGS)
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

	

# Compiler targets

CINC_PATH =
CINC_PATH += -I"../"
CINC_PATH += -I"../config"
CINC_PATH += -I"../CMSIS/Include"
CINC_PATH += -I"../include"
CINC_PATH += -I"../examples"
CINC_PATH += -I"../hal/include"
CINC_PATH += -I"../hal/utils/include"
CINC_PATH += -I"../hpl/core"
CINC_PATH += -I"../hpl/crya"
CINC_PATH += -I"../hpl/dmac"
CINC_PATH += -I"../hpl/gclk"
CINC_PATH += -I"../hpl/mclk"
CINC_PATH += -I"../hpl/nvmctrl"
CINC_PATH += -I"../hpl/osc32kctrl"
CINC_PATH += -I"../hpl/oscctrl"
CINC_PATH += -I"../hpl/pac"
CINC_PATH += -I"../hpl/pm"
CINC_PATH += -I"../hpl/port"
CINC_PATH += -I"../hpl/rtc"
CINC_PATH += -I"../hpl/sercom"
CINC_PATH += -I"../hpl/tram"
CINC_PATH += -I"../hpl/wdt"
CINC_PATH += -I"../hri"
CINC_PATH += -I"../trustzone"
CINC_PATH += -I"../stdio_redirect"

CFLAGS += -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse
CFLAGS += -D__SAML11E16A__ -march=armv8-m.base $(CINC_PATH)
CFLAGS += -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"
%.o: %.c
	@echo Building file: $<
	@echo ARM/GNU C Compiler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE)  $(CFLAGS)  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARM/GNU Assembler
	$(QUOTE)arm-none-eabi-as$(QUOTE) $(CFLAGS)  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARM/GNU Preprocessing Assembler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(CFLAGS)  -o "$@" "$<"
	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

# Quick load using edbg
load:
	edbg -t mchp_cm23 -p -f AtmelStarts.bin

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
