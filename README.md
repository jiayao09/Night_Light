
## SUMMARY:

I designed a night light for my hamster that controls the RGB-LED night light based on the human (or hamster) body infrared motion sensor and the current brightness of the environment. Additionally, according to UK Home Office advice, the temperature in the hamster chamber should be maintained consistently between 20 and 24 degrees Celsius. To make sure the hamster is in the best habitat, I have also included humidity and temperature detection. Last but not least, I included a color-changing mode in case the hamster ever decides to host a party.

A complete video was supposed to be here. (Still having hard time to film everything with two hands :), but the code is working!!!)


https://user-images.githubusercontent.com/110358483/211510444-115eef84-b0dc-48bd-b94e-4d2924034de6.mp4



## DETAIL:
</br>

* **3D printing && Laser Cutting part**
Include a 3D printing part (file is upload if you are interested in my duck) and laser cutting component (dxf file is attached) as a new decorative

<img src="https://user-images.githubusercontent.com/110358483/211921837-66123feb-cf87-4c14-91fe-4678f2c03e33.png" width=40% height=40%> <img src="https://user-images.githubusercontent.com/110358483/211923526-c8d1b310-ad55-4f20-ada7-d852fc5a77ab.jpg" width=40% height=40%>

* **Software**
The Duck Light's functionality is written in C++ using Arduino IDE. The android device is created with the editor of RemoteXY.com, which functions as a remote control to toggle the display mode and light mode. Bluetooth enables communication between the android device and the Duck Light.

<img src="https://user-images.githubusercontent.com/110358483/188025085-88aad158-057e-49c3-9915-8e68b34d2b3f.png" width=20% height=20%>


* **Circuit Connection**
![image](https://user-images.githubusercontent.com/110358483/211924026-98be2130-ea3f-4e76-8cbd-a0cdbe0ad21b.png)



## CURRENT DESIGN MODE:

###### Mode 1: detect mode

Sound sensor + brightness sensor 
When the brightness is low and Sound is detected, the night light will switch on.
  - the default color is white ( Can be change to different color)

###### Mode 2: Normal mode
1. On and off 
2. Change to set color (red, green, blue, purple, white)
3. Control by Andriod app 

###### Mode 3: Environment detector
1. Activate the OLED display and measure the current temperature, brightness, and humidity of the surrounding area.
2. Switch for OLED display screen

</br>
I know you are here for him, no one wants to check out a night light.

<img src="https://user-images.githubusercontent.com/110358483/185726824-95e51461-57ff-4efd-b0c1-65d19b495856.jpg" width=45% height=20%>



