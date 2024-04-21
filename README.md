# Arduino Genius Game Simulator

## Overview
This Arduino project is a simulation of the classic electronic game "Genius". It features a series of colored LEDs that illuminate in a specific sequence, which the player must then repeat by pressing the corresponding buttons. The game tests the player's memory as the sequences become progressively longer and more complex.

## Features
- Simulates the classic "Genius" game.
- Uses colored LEDs and buttons for player interaction.
- Generates random sequences of LED flashes for the player to repeat.
- Communicates game states via serial communication with text feedback.
- Adjustable difficulty levels.

## Hardware Requirements
- Arduino board (Arduino Uno R3).
- Colored LEDs (red, green, blue, yellow).
- Momentary push buttons (corresponding to the number of LEDs).
- Resistors for the LEDs (to limit current flow).
- Breadboard and jumper wires for circuit connections.

## Circuit Diagram

* Installation
1. Connect the LEDs and buttons to the Arduino board according to the provided circuit diagram.
2. Upload the Arduino sketch (genius_game.ino) to your Arduino board using the Arduino IDE.
3. Power on the Arduino board and start playing the game!

* Usage
1. Press the reset button or power on the Arduino to start a new game.
2. Pay attention to the sequence of LED flashes.
3. Repeat the sequence by pressing the corresponding buttons in the correct order.
4. If the sequence is correct, the game advances to the next round. If incorrect, the game ends.
5. The difficulty increases as the game progresses, challenging the player's memory and reflexes.
6. Repeat steps 1-5 to play again and try to beat your high score!

## Credits
This project was created by Edson Junior as a fun Arduino experiment inspired by the classic "Genius" game.

## License
This project is licensed under the MIT License.
