
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
SUB_DIRS +=  \
 \
examples \
hpl/oscctrl \
stdio_redirect/keil \
hpl/osc32kctrl \
trustzone \
hpl/dmac \
hal/src \
stdio_redirect \
hal/utils/src \
hpl/wdt \
hpl/rtc \
hpl/pm \
hpl/gclk \
hpl/tram \
hpl/mclk \
Secure_Functions \
temperature_sensor/at30tse75x \
hpl/pac \
hpl/sercom \
temperature_sensor \
hpl/nvmctrl \
hpl/core

# List the object files
OBJS +=  \
hal/src/hal_io.o \
stdio_redirect/stdio_io.o \
Secure_Functions/secure_pac.o \
hpl/wdt/hpl_wdt.o \
temperature_sensor/at30tse75x/at30tse75x.o \
hal/src/hal_pac.o \
Secure_Functions/secure_dataflash.o \
Secure_Functions/secure_temp_sensor.o \
trustzone/trustzone_manager.o \
hal/src/hal_i2c_m_sync.o \
Secure_Functions/secure_tram.o \
hal/src/hal_delay.o \
temperature_sensor_main.o \
main.o \
hpl/oscctrl/hpl_oscctrl.o \
hpl/core/hpl_init.o \
hal/src/hal_wdt.o \
hpl/rtc/rtc_lite.o \
hpl/pac/hpl_pac.o \
hpl/pm/hpl_pm.o \
app_veneer.o \
hal/src/hal_usart_sync.o \
hpl/mclk/hpl_mclk.o \
stdio_redirect/keil/Retarget.o \
Secure_Functions/secure_wdt.o \
hpl/gclk/hpl_gclk.o \
stdio_start.o \
Secure_Functions/secure_rtc.o \
hal/src/hal_init.o \
trustzone/trustzone_veneer.o \
hal/utils/src/utils_list.o \
hpl/osc32kctrl/hpl_osc32kctrl.o \
examples/driver_examples.o \
hpl/tram/tram_lite.o \
driver_init.o \
Secure_Functions/secure_led.o \
temperature_sensor/temperature_sensor.o \
Secure_Functions/secure_lowpower.o \
hpl/sercom/hpl_sercom.o \
hpl/core/hpl_core_m23_base.o \
hpl/nvmctrl/nvmctrl_lite.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_assert.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o \
hpl/dmac/hpl_dmac.o \
atmel_start.o \
hal/src/hal_atomic.o

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"stdio_redirect/stdio_io.o" \
"Secure_Functions/secure_pac.o" \
"hpl/wdt/hpl_wdt.o" \
"temperature_sensor/at30tse75x/at30tse75x.o" \
"hal/src/hal_pac.o" \
"Secure_Functions/secure_dataflash.o" \
"Secure_Functions/secure_temp_sensor.o" \
"trustzone/trustzone_manager.o" \
"hal/src/hal_i2c_m_sync.o" \
"Secure_Functions/secure_tram.o" \
"hal/src/hal_delay.o" \
"temperature_sensor_main.o" \
"main.o" \
"hpl/oscctrl/hpl_oscctrl.o" \
"hpl/core/hpl_init.o" \
"hal/src/hal_wdt.o" \
"hpl/rtc/rtc_lite.o" \
"hpl/pac/hpl_pac.o" \
"hpl/pm/hpl_pm.o" \
"app_veneer.o" \
"hal/src/hal_usart_sync.o" \
"hpl/mclk/hpl_mclk.o" \
"stdio_redirect/keil/Retarget.o" \
"Secure_Functions/secure_wdt.o" \
"hpl/gclk/hpl_gclk.o" \
"stdio_start.o" \
"Secure_Functions/secure_rtc.o" \
"hal/src/hal_init.o" \
"trustzone/trustzone_veneer.o" \
"hal/utils/src/utils_list.o" \
"hpl/osc32kctrl/hpl_osc32kctrl.o" \
"examples/driver_examples.o" \
"hpl/tram/tram_lite.o" \
"driver_init.o" \
"Secure_Functions/secure_led.o" \
"temperature_sensor/temperature_sensor.o" \
"Secure_Functions/secure_lowpower.o" \
"hpl/sercom/hpl_sercom.o" \
"hpl/core/hpl_core_m23_base.o" \
"hpl/nvmctrl/nvmctrl_lite.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_assert.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"hpl/dmac/hpl_dmac.o" \
"atmel_start.o" \
"hal/src/hal_atomic.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"Secure_Functions/secure_tram.d" \
"hpl/wdt/hpl_wdt.d" \
"stdio_redirect/stdio_io.d" \
"hal/utils/src/utils_event.d" \
"hal/src/hal_io.d" \
"hal/src/hal_pac.d" \
"Secure_Functions/secure_pac.d" \
"Secure_Functions/secure_dataflash.d" \
"temperature_sensor/at30tse75x/at30tse75x.d" \
"hal/src/hal_i2c_m_sync.d" \
"main.d" \
"Secure_Functions/secure_wdt.d" \
"trustzone/trustzone_manager.d" \
"hal/src/hal_wdt.d" \
"hpl/pac/hpl_pac.d" \
"hpl/rtc/rtc_lite.d" \
"temperature_sensor_main.d" \
"hal/src/hal_delay.d" \
"hpl/core/hpl_init.d" \
"hpl/pm/hpl_pm.d" \
"Secure_Functions/secure_rtc.d" \
"stdio_start.d" \
"hpl/gclk/hpl_gclk.d" \
"app_veneer.d" \
"hpl/dmac/hpl_dmac.d" \
"hal/src/hal_init.d" \
"hal/src/hal_usart_sync.d" \
"hal/utils/src/utils_assert.d" \
"stdio_redirect/keil/Retarget.d" \
"hpl/mclk/hpl_mclk.d" \
"driver_init.d" \
"hpl/tram/tram_lite.d" \
"temperature_sensor/temperature_sensor.d" \
"Secure_Functions/secure_temp_sensor.d" \
"Secure_Functions/secure_led.d" \
"hpl/osc32kctrl/hpl_osc32kctrl.d" \
"trustzone/trustzone_veneer.d" \
"examples/driver_examples.d" \
"hal/utils/src/utils_list.d" \
"hal/src/hal_sleep.d" \
"hpl/core/hpl_core_m23_base.d" \
"hpl/sercom/hpl_sercom.d" \
"Secure_Functions/secure_lowpower.d" \
"hal/src/hal_gpio.d" \
"hpl/nvmctrl/nvmctrl_lite.d" \
"hal/src/hal_atomic.d" \
"hpl/oscctrl/hpl_oscctrl.d" \
"atmel_start.d"

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

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARMCC Linker
	$(QUOTE)armlink$(QUOTE) --ro-base 0x00000000 --entry 0x00000000 --rw-base 0x20000000 --entry Reset_Handler --first __Vectors \
--strict --summary_stderr --info summarysizes --map --xref --callgraph --symbols \
--info sizes --info totals --info unused --info veneers --list $(OUTPUT_FILE_NAME).map \
-o $(OUTPUT_FILE_NAME).elf --cpu Cortex-M23 \
$(OBJS_AS_ARGS)

	@echo Finished building target: $@

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo ARMCC Compiler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M23 -D__SAML11E16A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/crya" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/mclk" -I"../hpl/nvmctrl" -I"../hpl/osc32kctrl" -I"../hpl/oscctrl" -I"../hpl/pac" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/rtc" -I"../hpl/sercom" -I"../hpl/tram" -I"../hpl/wdt" -I"../hri" -I"../config" -I"../trustzone" -I"../" -I"../config" -I"../stdio_redirect" -I"../" -I"../temperature_sensor" -I"../temperature_sensor/at30tse75x" -I"../" -I"../CMSIS/Include" -I"../include"  \
--depend "$@"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo ARMCC Assembler
	$(QUOTE)armasm$(QUOTE) -g --apcs=interwork --cpu Cortex-M23 --pd "D__SAML11E16A__ SETA 1" \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/crya" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/mclk" -I"../hpl/nvmctrl" -I"../hpl/osc32kctrl" -I"../hpl/oscctrl" -I"../hpl/pac" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/rtc" -I"../hpl/sercom" -I"../hpl/tram" -I"../hpl/wdt" -I"../hri" -I"../config" -I"../trustzone" -I"../" -I"../config" -I"../stdio_redirect" -I"../" -I"../temperature_sensor" -I"../temperature_sensor/at30tse75x" -I"../" -I"../CMSIS/Include" -I"../include"  \
--depend "$(@:%.o=%.d)" -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARMCC Preprocessing Assembler
	$(QUOTE)armcc$(QUOTE) --c99 -c -DDEBUG -O1 -g --apcs=interwork --split_sections --cpu Cortex-M23 -D__SAML11E16A__ \
-I"../" -I"../config" -I"../examples" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/crya" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/mclk" -I"../hpl/nvmctrl" -I"../hpl/osc32kctrl" -I"../hpl/oscctrl" -I"../hpl/pac" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/rtc" -I"../hpl/sercom" -I"../hpl/tram" -I"../hpl/wdt" -I"../hri" -I"../config" -I"../trustzone" -I"../" -I"../config" -I"../stdio_redirect" -I"../" -I"../temperature_sensor" -I"../temperature_sensor/at30tse75x" -I"../" -I"../CMSIS/Include" -I"../include"  \
--depend "$@"  -o "$@" "$<"

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
	rm -f $(OUTPUT_FILE_NAME).map $(OUTPUT_FILE_NAME).elf
