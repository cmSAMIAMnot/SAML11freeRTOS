Directories:

+ The main effort is in the following locations:
Demo/MICROCHIP_ATSAML11E16A_GCC/
Source/portable/GCC/AtmelSAML11/

Development:
+ Used the Zephyr toolchain, edbg, JLINK GDBserver, and atmel studio on windows.
The current current state of development for opensource tools supporting SAML11E16A
is lacking.  OpenOCD does not support the DAP version of the programmer on the 
Microchip SAML11 Xplained PRO or the processor architecture.  Programming the fuses
has also been a problem that required using atmel studio to fix.

See also -
http://www.freertos.org/FreeRTOS-quick-start-guide.html
http://www.freertos.org/FAQHelp.html
