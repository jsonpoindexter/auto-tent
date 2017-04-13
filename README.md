# auto-tent

Auotmate a camping tent.

Automation features:
1. Lights
2. Air

## Required Materials

* [Arduino](https://www.arduino.cc/) (currently for testing, will probably be changed to a embeded linux device)

Lights:

* [HC-SR501](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-hc-sr501-motion-sensor-tutorial/) Motion Sensor
* WS2811/12 LEDs

Air:

* TODO

## Installation

Lights:
1. Load the Arduino Sketch *auto-tent.ino* onto the Arduino.
2. Adjust the HC-SR501 PIR Range as needed. Described [here](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-hc-sr501-motion-sensor-tutorial/). **Current development testing at 3m**
3. Adjust the HC-SR501 Time Delay to 3 second (described in link above). 
4. Set the HC-SR501 Trigger Mode to *Repeatable Trigger* (described in link above). 
5. Connect the following pins on HC-SR501 Output pin to Pin 8 on the Arduino.
  * ![Alt text](auto-tent/img/PIRSensor_bb.jpg?raw=true "HC-SR501 Wiring")

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
  * I have had good results with: https://www.aliexpress.com/item/Free-Shipping-HC-SR501-Adjust-Infrared-IR-Pyroelectric-Infrared-PIR-module-Motion-Sensor-Detector-Module-We/32501142074.html?spm=2114.13010608.0.0.bWSciv
  Expect 20-30 day delivery time.

## History

TODO: Write history

## Credits

TODO: Write credits

## License

TODO: Write license
