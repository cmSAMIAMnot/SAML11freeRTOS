
#ifndef PARAT_H
#define PARAT_H

#include <hal_gpio.h>

void vParTestInitialise( void );
void vParTestToggleLED( unsigned long ulLED );
#define LED0 GPIO(GPIO_PORTA, 7)



#endif
