################################################################################
# TODO: add FreeRTOS files and remove all unneeded files
# 		build using stub
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

FREERTOS_ROOT=../../..

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf


CFLAGS += -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse
CFLAGS += -D__SAML11E16A__ -march=armv8-m.base
CFLAGS += -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"
#CFLAGS += -flto

SNFLAG= -Wl,--out-implib=libsecure_gateway_veneer.lib -Wl,--cmse-implib 

LDFLAGS += -Wl,--start-group -lm -Wl,--end-group -mthumb
LDFLAGS += -Wl,-Map=$(QUOTE)$(OUTPUT_FILE_NAME).map$(QUOTE)
LDFLAGS += --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base
#LDFLAGS += -nostdlib
#LDFLAGS += -flto
LDFLAGS += -T"../Device_Startup/saml11_secure.ld"
#LDFLAGS += -T"../Device_Startup/saml11_bl.ld"
LDFLAGS += -L"./Device_Startup"

# List the subdirectories for creating object files
SUB_DIRS += hpl/pm
SUB_DIRS += hpl/tc
SUB_DIRS += hpl/osc32kctrl
SUB_DIRS += trustzone
SUB_DIRS += hpl/dmac
SUB_DIRS += hal/src
SUB_DIRS += gcc
SUB_DIRS += hpl/mclk
SUB_DIRS += hal/utils/src
SUB_DIRS += hpl/sercom
SUB_DIRS += hpl/gclk
SUB_DIRS += hpl/oscctrl
SUB_DIRS += hpl/wdt
SUB_DIRS += gcc/gcc
SUB_DIRS += hpl/nvmctrl
SUB_DIRS += hpl/core
SUB_DIRS += hpl/tram
SUB_DIRS += $(FREERTOS_ROOT)/Source
SUB_DIRS += ParTest

# List the object files for dependencies
#OBJS += hal/src/hal_io.o
OBJS += gcc/system_saml11e16a.o
OBJS += gcc/gcc/startup_saml11e16a.o
#OBJS += Device_Startup/startup.o
#OBJS += hpl/wdt/hpl_wdt.o
#OBJS += hal/utils/src/utils_syscalls.o
#OBJS += hal/src/hal_spi_m_sync.o
#OBJS += hal/src/hal_timer.o
OBJS += hal/src/hal_delay.o
#OBJS += hpl/oscctrl/hpl_oscctrl.o
#OBJS += hpl/core/hpl_init.o
#OBJS += hal/src/hal_wdt.o
#OBJS += hal/utils/src/utils_assert.o
#OBJS += hpl/dmac/hpl_dmac.o
#OBJS += hpl/pm/hpl_pm.o
#OBJS += hal/src/hal_usart_sync.o
#OBJS += hpl/mclk/hpl_mclk.o
#OBJS += hpl/gclk/hpl_gclk.o
OBJS += hal/src/hal_init.o
#OBJS += hal/utils/src/utils_list.o
#OBJS += hpl/osc32kctrl/hpl_osc32kctrl.o
#OBJS += hpl/tram/tram_lite.o
#OBJS += hpl/sercom/hpl_sercom.o
OBJS += hpl/core/hpl_core_m23_base.o
#OBJS += hpl/nvmctrl/nvmctrl_lite.o
OBJS += hal/src/hal_gpio.o
#OBJS += hal/utils/src/utils_event.o
#OBJS += hal/src/hal_sleep.o
#OBJS += atmel_start.o
#OBJS += hpl/tc/hpl_tc.o
#OBJS += hal/src/hal_atomic.o
OBJS += $(FREERTOS_ROOT)/Source/tasks.o
OBJS += $(FREERTOS_ROOT)/Source/queue.o
OBJS += $(FREERTOS_ROOT)/Source/list.o
OBJS += $(FREERTOS_ROOT)/Source/timers.o
#0BJS += $(FREERTOS_ROOT)/Source/event_groups.o
#0BJS += $(FREERTOS_ROOT)/Source/croutine.o
OBJS += $(FREERTOS_ROOT)/Source/portable/MemMang/heap_1.o
OBJS += $(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11/port.o
OBJS += ParTest/ParTest.o
OBJS += main.o
OBJS += main-blinky.o

# Arguments for linker
OBJS_AS_ARGS := $(OBJS:%= "%")

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS := $(DEPS:%= "%")


# Establish the include directories
INCLUDE_PATH := $(SUB_DIRS:%= -I"%")
INCLUDE_PATH += -I$(QUOTE)$(FREERTOS_ROOT)/Demo/Common$(QUOTE) 
INCLUDE_PATH += -I$(QUOTE)$(FREERTOS_ROOT)/Source/include$(QUOTE) 
INCLUDE_PATH += -I$(QUOTE)$(FREERTOS_ROOT)/Demo/MICROCHIP_ATSAML11E16A_GCC$(QUOTE) 
INCLUDE_PATH += -I$(QUOTE)$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11$(QUOTE) 
INCLUDE_PATH += -I"./"
INCLUDE_PATH += -I"config" 
INCLUDE_PATH += -I"hal/include" 
INCLUDE_PATH += -I"hal/utils/include" 
INCLUDE_PATH += -I"hpl/port" 
INCLUDE_PATH += -I"hpl/sercom" 
INCLUDE_PATH += -I"hri" 
INCLUDE_PATH += -I"CMSIS/Include" 
INCLUDE_PATH += -I"include" 


vpath %.c ../
vpath %.s ../
vpath %.S ../
# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target
$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS)  \
$(INCLUDE_PATH) $(LDFLAGS) 

	@echo Finished building target: $@

	"arm-none-eabi-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"arm-none-eabi-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"arm-none-eabi-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"arm-none-eabi-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"arm-none-eabi-size" "$(OUTPUT_FILE_NAME).elf"

	

# Compiler targets



%.o: %.c
	@echo Building file: $<
	@echo ARM/GNU C Compiler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(CFLAGS) $(INCLUDE_PATH)  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARM/GNU Assembler
	$(QUOTE)arm-none-eabi-as$(QUOTE) $(CFLAGS) $(INCLUDE_PATH) -o "$@" "$<"
	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARM/GNU Preprocessing Assembler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) $(CFLAGS) $(INCLUDE_PATH)  -o "$@" "$<"
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
