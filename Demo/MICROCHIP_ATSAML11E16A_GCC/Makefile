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

# List the object files
#OBJS += hal/src/hal_io.o
OBJS += gcc/system_saml11e16a.o
OBJS += hpl/wdt/hpl_wdt.o
OBJS +=hal/utils/src/utils_syscalls.o \
hal/src/hal_spi_m_sync.o \
hal/src/hal_timer.o \
hal/src/hal_delay.o \
main.o \
hpl/oscctrl/hpl_oscctrl.o \
hpl/core/hpl_init.o \
hal/src/hal_wdt.o \
hal/utils/src/utils_assert.o \
hpl/dmac/hpl_dmac.o \
hpl/pm/hpl_pm.o \
hal/src/hal_usart_sync.o \
hpl/mclk/hpl_mclk.o \
hpl/gclk/hpl_gclk.o \
hal/src/hal_init.o \
hal/utils/src/utils_list.o \
hpl/osc32kctrl/hpl_osc32kctrl.o \
hpl/tram/tram_lite.o \
hpl/sercom/hpl_sercom.o \
hpl/core/hpl_core_m23_base.o \
hpl/nvmctrl/nvmctrl_lite.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o
#OBJS += atmel_start.o
OBJS += hpl/tc/hpl_tc.o \
hal/src/hal_atomic.o \
$(FREERTOS_ROOT)/Source/tasks.o \
$(FREERTOS_ROOT)/Source/queue.o \
$(FREERTOS_ROOT)/Source/portable/MemMang/heap_1.o \
$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11/port.o \
$(FREERTOS_ROOT)/Source/list.o \
ParTest/ParTest.o \
main-blinky.o

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"stdio_redirect/stdio_io.o" \
"gcc/system_saml11e16a.o" \
"hpl/wdt/hpl_wdt.o" \
"gcc/gcc/startup_saml11e16a.o" \
"stdio_redirect/gcc/write.o" \
"hal/utils/src/utils_syscalls.o" \
"stdio_redirect/gcc/read.o" \
"hal/src/hal_spi_m_sync.o" \
"trustzone/trustzone_manager.o" \
"hal/src/hal_timer.o" \
"hal/src/hal_delay.o" \
"main.o" \
"hpl/oscctrl/hpl_oscctrl.o" \
"hpl/core/hpl_init.o" \
"hal/src/hal_wdt.o" \
"hal/utils/src/utils_assert.o" \
"hpl/dmac/hpl_dmac.o" \
"hpl/pm/hpl_pm.o" \
"hal/src/hal_usart_sync.o" \
"hpl/mclk/hpl_mclk.o" \
"hpl/gclk/hpl_gclk.o" \
"stdio_start.o" \
"hal/src/hal_init.o" \
"trustzone/trustzone_veneer.o" \
"hal/utils/src/utils_list.o" \
"hpl/osc32kctrl/hpl_osc32kctrl.o" \
"examples/driver_examples.o" \
"hpl/tram/tram_lite.o" \
"driver_init.o" \
"hpl/sercom/hpl_sercom.o" \
"hpl/core/hpl_core_m23_base.o" \
"hpl/nvmctrl/nvmctrl_lite.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"atmel_start.o" \
"hpl/tc/hpl_tc.o" \
"hal/src/hal_atomic.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"hpl/wdt/hpl_wdt.d" \
"gcc/system_saml11e16a.d" \
"stdio_redirect/stdio_io.d" \
"hal/utils/src/utils_event.d" \
"hal/src/hal_io.d" \
"hal/utils/src/utils_syscalls.d" \
"stdio_redirect/gcc/write.d" \
"main.d" \
"hal/src/hal_timer.d" \
"trustzone/trustzone_manager.d" \
"hal/src/hal_spi_m_sync.d" \
"gcc/gcc/startup_saml11e16a.d" \
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

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

# Establish the include directories
INCLUDE_PATH= \
-I$(FREERTOS_ROOT)/Demo/Common \
-I$(FREERTOS_ROOT)/Source/include \
-I$(FREERTOS_ROOT)/Demo/MICROCHIP_ATSAML11E16A_GCC \
-I$(FREERTOS_ROOT)/Source/portable/GCC/AtmelSAML11 \
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

SNFLAG=-Wl,--out-implib=libsecure_gateway_veneer.lib -Wl,--cmse-implib 

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS) -Wl,--start-group -lm -Wl,--end-group -mthumb \
-Wl,-Map="$(OUTPUT_FILE_NAME).map" --specs=nano.specs -Wl,--gc-sections -march=armv8-m.base \
$(INCLUDE_PATH) \
 \
-T"../Device_Startup/saml11_secure.ld" \
-L"./Device_Startup"
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
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse \
-D__SAML11E16A__ -march=armv8-m.base  \
$(INCLUDE_PATH) \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARM/GNU Assembler
	$(QUOTE)arm-none-eabi-as$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse \
-D__SAML11E16A__ -march=armv8-m.base  \
$(INCLUDE_PATH) \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARM/GNU Preprocessing Assembler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 -Wall -c -std=gnu99 -mcmse \
-D__SAML11E16A__ -march=armv8-m.base  \
$(INCLUDE_PATH) \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
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
