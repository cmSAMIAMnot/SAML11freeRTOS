
======================
Trust RAM Lite driver
======================
The TrustRAM (TRAM) is the controller interface for a on-chip security RAM.
This RAM is intended for volatile secret data in a SmartSecure MCU.

The main TRAM parameters that can be configured in START, and will be initialized
by the TRAM driver.

Features
--------
* Initialization
* R/W to security RAM

Applications
------------
* Security applications

Dependencies
------------
* CLKCTRL for clocks
* EVSYS for events
* CPUINT for interrupt

Concurrency
-----------
N/A

Limitations
-----------
N/A

Knows issues and workarounds
----------------------------
N/A

