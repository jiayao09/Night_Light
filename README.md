SUMMARY:

I designed a night light for my hamster that controls the RGB-LED night light based on the human (or hamster) body infrared motion sensor and the current brightness of the environment. Additionally, according to UK Home Office advice, the temperature in the hamster chamber should be maintained consistently between 20 and 24 degrees Celsius. To make sure the hamster is in the best habitat, I have also included humidity and temperature detection. Last but not least, I included a color-changing mode in case the hamster ever decides to host a party.

I created my own circuit board to replace a breadboard because everything would be packed into a tiny package delivery box. The circuit was designed as follows：

<img src="https://user-images.githubusercontent.com/110358483/185727129-fb4031ba-f6d2-470d-9bae-8b3f75dd295e.png" width=45% height=20%>

Final view before I package everything in the box.

<img src="https://user-images.githubusercontent.com/110358483/185731587-1e23c9e0-f1e7-4f95-9565-a4e1113caf48.jpg" width=45% height=20%>

RECENT UPDATE:

- Include a 3D printing feature and a laser cutting component as a new decorative

- To get a more colorful duck, swap RGB-LED with Ws2812.

- Switch from the IR infrared sensor to the more stable Bluetooth sensor, which can be controlled by an Android app.

- Lights can be changed based on the music by replacing the sound sensor with an IR (infrared) human motion sensor.

![nn02](https://user-images.githubusercontent.com/110358483/187520013-15501308-0dbe-4ed0-9a37-edb5db9f598a.png)


https://user-images.githubusercontent.com/110358483/187514166-f22852cb-fc70-40c8-b927-e4e7bea9ec13.mp4



</br>
CURRENT DESIGN MODE:

</br>
Mode 1: detect mode:
IR Infrared + brightness sensor 
When the brightness is low and human motion is detected, the night light will switch on.
  - the default color is white ( Can be change to different color)
  
https://user-images.githubusercontent.com/110358483/185727114-b6bb8073-501c-42c4-ac30-aa270a14f70a.mp4

</br>
Mode 2: Normal mode:

</br> 1. on and off 
</br> 2. Change to set color (red, green, blue, purple, white)
</br>
</br>
Mode 3: Environment detector:
</br>
</br> Activate the OLED display and measure the current temperature, brightness, and humidity of the surrounding area.

</br>
I know you are here for him, no one wants to check out a night light.

<img src="https://user-images.githubusercontent.com/110358483/185726824-95e51461-57ff-4efd-b0c1-65d19b495856.jpg" width=45% height=20%>



