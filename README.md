# IntroductionToRobotics

<details>
  
<summary>HOMEWORK #1</summary>
<br>
  
### As was described in the laboratory, the homework consists of the following:

  • Components: RBG led (1 minimum), potentiometers (3 minimum), resistors and wires (per logic)

  • Technical Task: Use a separat potentiometer in controlling each of thecolor of the RGB led (Red, Green andBlue). The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connectedto the led.
 
 Link to Youtube video --> https://youtu.be/2Q2uAz9449w

<br>
<img src="https://user-images.githubusercontent.com/41235115/139037978-5155c4df-429a-4cb4-9c96-6dde834d50db.jpeg" data-canonical-src="https://user-images.githubusercontent.com/41235115/139037978-5155c4df-429a-4cb4-9c96-6dde834d50db.jpeg" width="200" height="400" />
  
</details>
  
  

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
