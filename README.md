# IntroductionToRobotics
 In "Homework #1" I am using three potentiometers to control the intensity of the three RGB LED colors
<details>
  
<summary>HOMEWORK #1</summary>
<br>
  
### As was described in the laboratory, the homework consists of the following:

  • Components: RBG led (1 minimum), potentiometers (3 minimum), resistors and wires (per logic)

  • Technical Task: Use a separate potentiometer in controlling each of the colors of the RGB led (Red, Green and Blue). The control must be done with digital electronics.
 
 Link to Youtube video --> https://youtu.be/2Q2uAz9449w

<br>
<img src="https://user-images.githubusercontent.com/41235115/139037978-5155c4df-429a-4cb4-9c96-6dde834d50db.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/139037978-5155c4df-429a-4cb4-9c96-6dde834d50db.jpeg" width="200" height="400" />
  
</details>
  
<br>
 In "Homework #2" I created a traffic lights system
<details>
  
<summary>HOMEWORK #2</summary>
<br>

### As was described in the laboratory, the homework consists of the following:

• Components: 5 LEDs, 1 button, 1 buzzer, resistors and wires (per logic)

• General description: Building the traffic lights for a crosswalk. You
will use 2 LEDs to represent the traffic lights for people (red and green)
and 3 LEDs to represent the traffic lights for cars (red, yellow and green).
See the states it needs to go through. If anything is not clear, ask. Also,
see the uploaded video (the intervals are different, but the states flow is
the same). It’s a traffic lights system for people and cars - don’t overthink
it.

### The system has the following states:
<br>
  
•  State 1 (default, reinstated after state 4 ends): green light for cars,
red light for people, no sounds.
##### Duration: indefinite, changed by pressing the button.
<br>

•  State 2 (initiated by counting down 10 seconds after a button press):
the light should be yellow for cars, red for people and no sounds.
##### Duration: 3 seconds.
<br>

•  State 3 (iniated after state 2 ends): red for cars, green for people and
a beeping sound from the buzzer at a constant interval. 
##### Duration: 10 seconds.
<br>

•  State 4 (initiated after state 3 ends): red for cars, blinking green
for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3.
##### Duration: 5 seconds.

 Link to Youtube video --> https://youtu.be/ksTUSur19TU
  
<br>
<img src="https://user-images.githubusercontent.com/41235115/140101081-f81d9dcd-6221-49f8-9abc-f00f20a25fa4.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/140101081-f81d9dcd-6221-49f8-9abc-f00f20a25fa4.jpeg" width="200" height="400" />

</details>

<br>
 In "Homework #3" I created an EMF Detector
<details>
  
<summary>HOMEWORK #3</summary>
<br>

### As was described in the laboratory, the homework consists of the following:

Components: a buzzer and a 7-segment display
<br>
Task: should detect EMF (check body and near outlets). It prints the value on the 7-segment display and makes a sound based on the intensity.

 Link to Youtube video --> https://youtu.be/NC3r56AXqPA
  
<br>
<img src="https://user-images.githubusercontent.com/41235115/141155511-a3b6c669-4029-4911-bce4-2912ad14e454.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/141155511-a3b6c669-4029-4911-bce4-2912ad14e454.jpeg" width="200" height="400" />
<br>
<img src="https://user-images.githubusercontent.com/41235115/141155627-d229486f-e389-4fe4-b7d9-2ab58b9c83ef.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/141155627-d229486f-e389-4fe4-b7d9-2ab58b9c83ef.jpeg" width="200" height="400" />

</details>

<br>

In "Homework #4" I am using a 4 Digit 7 Segment LED to display a number, it is adjusted using a Joystick
<details>
  
<summary>HOMEWORK #4</summary>
<br>
  
### As was described in the laboratory, the homework consists of the following:

  • Components: a joystick, a 4 digit 7-segment display, a 74hc595 shiftregister

  • Technical Task: 
 First State: you can use a joystick axis to cycle through the 4 digits; using the other axis does nothing. A blinking decimal point shows the current digit position. When pressing the button, you lock in on the selected digit and enter the second state.
<br>
 Second State: In this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle through the 4 digits. Instead, using the other axis, you can increment or decrement the number on the current digit. Pressing the button again returns you to the previous state. 
 Bonus: Save the last value in eeprom and load it when starting arduino. Also, keep in mind that when changing the number, you must increment it for each joystick movement - it should not work continuosly increment if you keep the joystick in one position.
 
 Link to Youtube video --> https://youtu.be/dPsJHL-VblA 

<br>
<img src="https://user-images.githubusercontent.com/41235115/142236220-deec7d86-c24f-4fde-a169-840a81a451e4.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/142236220-deec7d86-c24f-4fde-a169-840a81a451e4.jpeg" width="400" height="200" />
 <br>
<img src="https://user-images.githubusercontent.com/41235115/142236561-7336ebf9-e188-4e40-858d-76cc8bbafbbb.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/142236561-7336ebf9-e188-4e40-858d-76cc8bbafbbb.jpeg" width="400" height="200" />
 <br>
<img src="https://user-images.githubusercontent.com/41235115/142236690-2eef642c-3e68-4814-91d3-59e99dc2c953.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/142236690-2eef642c-3e68-4814-91d3-59e99dc2c953.jpeg" width="400" height="200" />
</details>



