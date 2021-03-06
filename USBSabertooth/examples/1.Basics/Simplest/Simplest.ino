// Simplest Sample for USB Sabertooth Packet Serial
// Copyright (c) 2012-2013 Dimension Engineering LLC
// See license.txt for license details.

#include <USBSabertooth.h>

USBSabertoothSerial C; // Use the Arduino TX pin. It connects to S1.
                       // See the SoftwareSerial example in 3.Advanced for how to use other pins.

USBSabertooth ST(C, 128); // The USB Sabertooth is on address 128 (unless you've changed it with DEScribe).
                          // We'll name its object ST.
                          //
                          // If you've set up your Sabertooth on a different address, of course change
                          // that here. For how to configure the Sabertooth, see the DIP Switch Wizard at
                          //   http://www.dimensionengineering.com/datasheets/USBSabertoothDIPWizard/start.htm
                          // Be sure to select Packet Serial Mode for use with this library.
                          //
                          // The USBSabertooth library exposes features that only exist on USB-enabled Sabertooth motor drivers, such as
                          // 12-bit motor outputs, power outputs, control over freewheeling, motor current read-back, and User Mode variables.
                          // If you do not need these features, and want your code to be compatible with all Sabertooth/SyRen motor drivers,
                          // including those that are not USB-enabled, use the Sabertooth library instead.
                                        
void setup()
{
  SabertoothTXPinSerial.begin(9600); // 9600 is the default baud rate for Sabertooth Packet Serial.
                                     // You can change this with the DEScribe software, available at
                                     //   http://www.dimensionengineering.com/describe
}

void loop()
{
  ST.motor(1, 2047);  // Go forward at full power.
  delay(2000);        // Wait 2 seconds.
  ST.motor(1, 0);     // Stop.
  delay(2000);        // Wait 2 seconds.
  ST.motor(1, -2047); // Reverse at full power.
  delay(2000);        // Wait 2 seconds.
  ST.motor(1, 0);     // Stop.
  delay(2000);
}

