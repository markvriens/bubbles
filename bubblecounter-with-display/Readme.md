# Project - Bubble counter with a display - ESP8266

Using:
- adafruit-feather-huzzah-esp8266 [ref](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/overview)
- ir-breakbeam-sensors [ref](https://learn.adafruit.com/ir-breakbeam-sensors/arduino)
- display (Seriële Witte OLED Display Module 128X64 I2C SSD1306 12864 Lcd-scherm)
- beer fermentation airlock [ref example](https://www.braumarkt.com/waterslot-bolletjesmodel)

## Description




## Schema

The project is made with the following schema. On the right side the ir-breambeam sensors connected with the white kabel to the 10kOhm resistor and pin 16 of the feather. The powersupply comes from the feather pin (3.3V).

![electronic schema](./img/schema.jpg)

## Case with the display

|Name|Description|
|--|--|
|Title | -=BUBBLES=-|
|Total | All counted bubbles when the arduino starts
|Max   (U/D) | Maximum SUM of all bubbles in a hour with measuring if its rizing or not U (Up) or D(Down)|
|COUNTER| Minute counter. Every minute its reset this value|


![electronic schema](./img/box_display.jpg)

## IR-breakbeam sensor

The breakbeam sensor has been stick in a case with the air lock. This is for external light and solid layer. Before connected to the fermentor. For first use the sensors has to been calibrated before it counts the bubbles. 

![electronic schema](./img/breaksensor-1.jpg)
![electronic schema](./img/breaksensor-2.jpg)

## Total project

![electronic schema](./img/project-total.jpg)

## Arduino code

### Librarie

- 8x8lib control the display [ref](https://github.com/olikraus/u8g2/wiki)


## Future requirement

- WIFI connection
- Temparature
- Connected to a open platform like (Ubidots)
