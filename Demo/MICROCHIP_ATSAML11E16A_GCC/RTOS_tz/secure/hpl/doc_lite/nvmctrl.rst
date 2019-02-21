======================
NVMCTRL driver
======================
Non-Volatile Memory (NVM) is a re-programmable Flash memory that retains program and data storage
even with power off. It embeds three separate arrays namely FLASH, DATA FLASH and AUX FLASH.

This NVMCTRL lite driver provide basic interface to operate FLASH, DATA FLASH and AUX FLASH.

Features
--------
* Initialization
* Read NVM
* Erase row
* Write page buffer
* Write page (program page)
* Execute NVM command
* Macros to access AUX FLASH (UROW, BOCOR)

Applications
------------
* Application to operate NVM

Dependencies
------------
* CLKCTRL for clocks

Concurrency
-----------
N/A

Limitations
-----------
N/A

Knows issues and workarounds
----------------------------
N/A

