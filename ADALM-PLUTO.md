# ADALM-PLUTO

This is setup tutorial for ADALM-PLUTO Software Define Radio and its operation on MATLAB.

## Table of Contents
- [Prerequisite](#Prerequisite)
- [MATLAB](#MATLAB)
- [Installing Drivers](#Installing-Drivers)
- [MATLAB toolbox installation](#MATLAB-toolbox-installation)
- [Installing Firmware](#Installing-Firmware)
- [Operation of FM Radio](#Operation-of-FM-Radio)

## Prerequisite
- [MATLAB](https://www.mathworks.com/products/matlab.html)
  - Digital Signal Processing System Toolbox
  - Signal Processing Toolbox
  - Communications Toolbox Support Package for Analog Devices ADALM-Pluto Radio
- [ADALM-PLUTO Software Defined Radio](https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/adalm-pluto.html)

## MATLAB

MATLAB Version 2017 or later for operation of the radio. (configuration of the radio is not possible versions before 2022) 

MATLAB Verison 2022 or later for both operation of the radio and configuration.

## Installing Drivers
Open the box, once you have opened the box there should be 5 items should be present
  - 1 ADALM-PLUTO Software Defined Radio
  - 1 Pair of Antenna
  - 1 USB-A to USB-micro
  - USB-micro to serial bus
  
After making sure all the parts are present, install the [driver](https://wiki.analog.com/university/tools/pluto/drivers/windows). The driver used for
this tutorial is created on ```06 Apr 2022 12:22```.

Follow the steps provided in the installation process to install the driver on Windows machine 32-bit / 64-bit. Once the driver is installed, plug in the ADALM-PLUTO
to your Windows Machine.

## MATLAB toolbox installation

The ADALM-PLUTO needs two toolbox to work on MATLAB, ```Digital Signal Processing System Toolbox``` and ```Signal Processing Toolbox```.

Once these two toolboxes are installed, you can search ADALM-PLUTO on MATLAB toolboxes called ```Communications Toolbox Support Package for Analog Devices ADALM-Pluto Radio```, but do not run the installation process through this toolbox.

## Installing Firmware

Plug in the USB-micro to USB-A into the PLUTO, PLUTO takes USB-micro and Windows machine should take USB-A.
Once you plugged in the Windows machine, you will be firmware folder of the PLUTO will appear.
Open up ```info.html``` file in the directory and press ```firmware```, and check if your verison of hardware is ```v0.31``` or above.

Then continue installation process with MATLAB toolbox installation for ADALM-PLUTO. MATLAB will automatcially install all required drivers for both
the computer and ADALM-PLUTO Radio.

**When MATLAB direct you to install v0.31, only install v0.31 when you have outdated firmware. Cannot guarantee if PLUTO Radio and MATLAB will work outdated verisons of firmware**

**MAKE SURE THAT RADIO DOES NOT LOSE POWER WHILE UPDATING THE FIRMWARE, ONCE RADIO LOSE POWER DURING FIRMWARE UPDATE WILL RESULT IN BRICKING YOUR RADIO**

## Operation of FM Radio

Upon completion of installing ADALM-PLUTO Toolbox, there will be multiple examples of codes for this Radio.
Pick ```FMReceiverExample.m``` from MATLAB addon manager or go to this directory to manually pick the file

``` C:\Program Files\MATLAB\R2021b\toolbox\comm\commdemos\FMReceiverExample.m ```

After opening the file, check Radio is prepared to operate 
 - PLUTO Radio is connected to the computer
 - PLUTO Radio has its antenna connected
 - PLUTO Radio is turned on
 - MATLAB has all required toolboxes installed as directed above

Once the radio is prepared, run the following command to configure the radio for the machine. This command will configure the radio to connected to MATLAB and set the software to process the FM radio signals. The configuration of the radio only works with MATLAB version after 2022, make sure your MATLAB is upto date for this operation.

```configurePlutoRadio('AD9364','usb:0')```

Once the radio is configured, run the matlab file. It will direct you the process on the command line window, and settings as follows.
1. Time to record and receive the radio signal
2. Mode of Radio (Run option 3 to run ADALM-PULTO Radio)
3. Frequency (Within range of 88.0 MHz to 108.0 MHz, and must be represented into all digit. ex. 98300000 for 98.3 MHz)

It will take few minutes for radio to receive and process while you are able to hear from the computer, after processing is done you will be able to listen to the radio, make sure that the radio frequency is set to local radio frequency, or you will near nothing but static noise.
