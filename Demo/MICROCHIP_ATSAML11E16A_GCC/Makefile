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

FREERTOS_ROOT=../..

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf


CFLAGS += -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse
CFLAGS += -D__SAML11E16A__ -march=armv8-m.base
CFLAGS += -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"
CFLAGS += -flto

SNFLAG=-Wl,--out-implib=libsecure_gateway_veneer.lib -Wl,--cmse-implib 

LDFLAGS += -Wl,--start-group -lm -Wl,--end-group -mthumb
LDfLAGS += -Wl,-Map="$(OUTPUT_FILE_NAME).map"
LDFLAGS += --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base
LDFLAGS += -nostdlib
#LDFLAGS += -flto
#LDFLAGS += -T"../Device_Startup/saml11_secure.ld"
LDFLAGS += -T"../Device_Startup/saml11_bl.ld"
LDFLAGS += -L"./Device_Startup"

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
hpl/pm \
hpl/tc \
hpl/osc32kctrl \
trustzone \
hpl/dmac \
hal/src \
gcc \
hpl/mclk \
hal/utils/src \
hpl/sercom \
hpl/gclk \
hpl/oscctrl \
hpl/wdt \
gcc/gcc \
hpl/nvmctrl \
hpl/core \
hpl/tram \
$(FREERTOS_ROOT)/Source \
ParTest

# List the object files for dependencies
#OBJS += hal/src/hal_io.o
#OBJS += gcc/system_saml11e16a.o
OBJS += Device_Startup/startup.o
#OBJS += hpl/wdt/hpl_wdt.o
#OBJS += hal/utils/src/utils_syscalls.o
#OBJS += hal/src/hal_spi_m_sync.o
#OBJS += hal/src/hal_timer.o
#OBJS += hal/src/hal_delay.o
#OBJS += hpl/oscctrl/hpl_oscctrl.o
#OBJS += hpl/core/hpl_init.o
#OBJS += hal/src/hal_wdt.o
#OBJS += hal/utils/src/utils_assert.o
#OBJS += hpl/dmac/hpl_dmac.o
#OBJS += hpl/pm/hpl_pm.o
#OBJS += hal/src/hal_usart_sync.o
#OBJS += hpl/mclk/hpl_mclk.o
#OBJS += hpl/gclk/hpl_gclk.o
#OBJS += hal/src/hal_init.o
#OBJS += hal/utils/src/utils_list.o
#OBJS += hpl/osc32kctrl/hpl_osc32kctrl.o
#OBJS += hpl/tram/tram_lite.o
#OBJS += hpl/sercom/hpl_sercom.o
#OBJS += hpl/core/hpl_core_m23_base.o
#OBJS += hpl/nvmctrl/nvmctrl_lite.o
#OBJS += hal/src/hal_gpio.o
#OBJS += hal/utils/src/utils_event.o
#OBJS += hal/src/hal_sleep.o
#OBJS += atmel_start.o
#OBJS += hpl/tc/hpl_tc.o
#OBJS += hal/src/hal_atomic.o
OBJS += $(FREERTOS_ROOT)/Source/tasks.o
OBJS += $(FREERTOS_ROOT)/Source/queue.o
OBJS += $(FREERTOS_ROOT)/Source/portable/MemMang/heap_1.o
OBJS += $(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11/port.o
0BJS += $(FREERTOS_ROOT)/Source/list.o
OBJS += ParTest/ParTest.o
OBJS += main.o
OBJS += main-blinky.o

# Arguments for linker
#OBJS_AS_ARGS += "hal/src/hal_io.o"
#OBJS_AS_ARGS += "gcc/system_saml11e16a.o"
OBJS_AS_ARGS += "Device_Startup/startup.o"
#OBJS_AS_ARGS += "hpl/wdt/hpl_wdt.o"
#OBJS_AS_ARGS += "hal/utils/src/utils_syscalls.o"
#OBJS_AS_ARGS += "hal/src/hal_spi_m_sync.o"
#OBJS_AS_ARGS += "trustzone/trustzone_manager.o"
#OBJS_AS_ARGS += "hal/src/hal_timer.o"
#OBJS_AS_ARGS += "hal/src/hal_delay.o"
OBJS_AS_ARGS += "main.o"
OBJS_AS_ARGS += "main-blinky.o"
#OBJS_AS_ARGS += "hpl/oscctrl/hpl_oscctrl.o"
#OBJS_AS_ARGS += "hpl/core/hpl_init.o"
#OBJS_AS_ARGS += "hal/src/hal_wdt.o"
#OBJS_AS_ARGS += "hal/utils/src/utils_assert.o"
#OBJS_AS_ARGS += "hpl/dmac/hpl_dmac.o"
#OBJS_AS_ARGS += "hpl/pm/hpl_pm.o"
#OBJS_AS_ARGS += "hal/src/hal_usart_sync.o"
#OBJS_AS_ARGS += "hpl/mclk/hpl_mclk.o"
#OBJS_AS_ARGS += "hpl/gclk/hpl_gclk.o"
#OBJS_AS_ARGS += "stdio_start.o"
#OBJS_AS_ARGS += "hal/src/hal_init.o"
#OBJS_AS_ARGS += "trustzone/trustzone_veneer.o"
#OBJS_AS_ARGS += "hal/utils/src/utils_list.o"
#OBJS_AS_ARGS += "hpl/osc32kctrl/hpl_osc32kctrl.o"
#OBJS_AS_ARGS += "hpl/tram/tram_lite.o"
#OBJS_AS_ARGS += "hpl/sercom/hpl_sercom.o"
#OBJS_AS_ARGS += "hpl/core/hpl_core_m23_base.o"
#OBJS_AS_ARGS += "hpl/nvmctrl/nvmctrl_lite.o"
#OBJS_AS_ARGS += "hal/src/hal_gpio.o"
#OBJS_AS_ARGS += "hal/utils/src/utils_event.o"
#OBJS_AS_ARGS += "hal/src/hal_sleep.o"
#OBJS_AS_ARGS += "atmel_start.o"
#OBJS_AS_ARGS += "hpl/tc/hpl_tc.o"
#OBJS_AS_ARGS += "hal/src/hal_atomic.o"
OBJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/tasks.o$(QUOTE)
OBJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/tasks.o$(QUOTE)
OBJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/queue.o$(QUOTE)
OBJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/portable/MemMang/heap_1.o$(QUOTE)
OBJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11/port.o$(QUOTE)
0BJS_AS_ARGS += $(QUOTE)$(FREERTOS_ROOT)/Source/list.o$(QUOTE)
OBJS_AS_ARGS += "ParTest/ParTest.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"hpl/wdt/hpl_wdt.d" \
"gcc/system_saml11e16a.d" \
"hal/utils/src/utils_event.d" \
"hal/src/hal_io.d" \
"hal/utils/src/utils_syscalls.d" \
"main.d" \
"hal/src/hal_timer.d" \
"trustzone/trustzone_manager.d" \
"hal/src/hal_spi_m_sync.d" \
"hal/src/hal_wdt.d" \
"hpl/dmac/hpl_dmac.d" \
"hal/utils/src/utils_assert.d" \
"hal/src/hal_delay.d" \
"hpl/core/hpl_init.d" \
"hpl/pm/hpl_pm.d" \
"stdio_start.d" \
"hpl/gclk/hpl_gclk.d" \
"hal/src/hal_init.d" \
"hal/src/hal_usart_sync.d" \
"hpl/mclk/hpl_mclk.d" \
"driver_init.d" \
"hpl/tram/tram_lite.d" \
"stdio_redirect/gcc/read.d" \
"hpl/osc32kctrl/hpl_osc32kctrl.d" \
"trustzone/trustzone_veneer.d" \
"examples/driver_examples.d" \
"hal/utils/src/utils_list.d" \
"hal/src/hal_sleep.d" \
"hpl/core/hpl_core_m23_base.d" \
"hpl/sercom/hpl_sercom.d" \
"hal/src/hal_gpio.d" \
"hpl/nvmctrl/nvmctrl_lite.d" \
"hal/src/hal_atomic.d" \
"hpl/tc/hpl_tc.d" \
"hpl/oscctrl/hpl_oscctrl.d" \
"atmel_start.d"


# Establish the include directories
INCLUDE_PATH= \
-I$(QUOTE)$(FREERTOS_ROOT)/Demo/Common$(QUOTE) \
-I$(QUOTE)$(FREERTOS_ROOT)/Source/include$(QUOTE) \
-I$(QUOTE)$(FREERTOS_ROOT)/Demo/MICROCHIP_ATSAML11E16A_GCC$(QUOTE) \
-I$(QUOTE)$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11$(QUOTE) \
-I"./" \
-I"config" \
-I"hal/include" \
-I"hal/utils/include" \
-I"hpl/core" \
-I"hpl/crya" \
-I"hpl/dmac" \
-I"hpl/gclk" \
-I"hpl/mclk" \
-I"hpl/nvmctrl" \
-I"hpl/osc32kctrl" \
-I"hpl/oscctrl" \
-I"hpl/pm" \
-I"hpl/port" \
-I"hpl/sercom" \
-I"hpl/tc" \
-I"hpl/tram" \
-I"hpl/wdt" \
-I"hri" \
-I"config" \
-I"trustzone" \
-I"config" \
-I"CMSIS/Include" \
-I"include" \
-I"ParTest"


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
