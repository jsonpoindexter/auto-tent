# auto-tent

Auotmate a camping tent.

Automation features:
1. Lights

    Demo: 
    <iframe width="560" height="315" src="https://www.youtube.com/embed/bbWn63K64jY" frameborder="0" allowfullscreen></iframe>

## Required Materials
*Purchasing links can be found in the Purchasing section*

* [Arduino](https://www.arduino.cc/)
* [HC-SR501](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-hc-sr501-motion-sensor-tutorial/) Motion Sensor
* WS2811/12 LEDs (I suggest 12mm diffused)
* [Battery Pack](https://www.amazon.com/Anker-bar-Sized-Portable-High-Speed-Technology/dp/B00P7N0320/ref=sr_1_4?s=wireless&ie=UTF8&qid=1492446490&sr=1-4&keywords=battery+pack)

## Installation

Lights:
1. Load the Arduino Sketch *auto-tent.ino* onto the Arduino.
2. Adjust the HC-SR501 PIR Range as needed. Described [here](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-hc-sr501-motion-sensor-tutorial/). **Current development testing at 3m**
3. Adjust the HC-SR501 Time Delay to 3 second (described in link above). 
4. Set the HC-SR501 Trigger Mode to *Repeatable Trigger* (described in link above). 
5. Connect the following pins (Power, Gound, Data Out) on HC-SR501 to the Arduino.
![](/img/PIRSensor_bb.jpg?raw=true "HC-SR501 Wiring")

## Usage

TODO: Write usage instructions

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

## Purchasing
* HC-SR501
  * I have had good results with: [AliExpress](https://www.aliexpress.com/item/Free-Shipping-HC-SR501-Adjust-Infrared-IR-Pyroelectric-Infrared-PIR-module-Motion-Sensor-Detector-Module-We/32501142074.html?spm=2114.13010608.0.0.bWSciv)
  Expect 20-30 day delivery time.
* WS2811 12mm Diffused
  [AliExpress](https://www.aliexpress.com/item/50PCS-lots-DC5V-12V-WS2811-WS2801-RGB-IC-led-pixel-module-12mm-Digital-Full-Color-Independently/32676844336.html?ws_ab_test=searchweb0_0,searchweb201602_5_10152_10065_10151_10068_10130_5100014_10136_10137_10060_10138_10062_10156_10056_10055_10054_10059_10099_10103_10102_10096_10148_10147_10052_10053_10142_10107_10050_10143_10051_10084_10083_10080_10082_10081_10178_10110_10111_10112_10113_10114_10037_10033_10032_10078_10079_10077_10073_10070_10123_10124-10051_10032_10033_10037,searchweb201603_1,afswitch_1,ppcSwitch_5&btsid=727712c8-1875-4d5e-bb8c-2c302d7a7b2b&algo_expid=87d2cb21-1d25-4b93-bd79-6397482fb75d-10&algo_pvid=87d2cb21-1d25-4b93-bd79-6397482fb75d) **5v 2811**
  

## History

TODO: Write history

## Credits

TODO: Write credits

## License

TODO: Write license
