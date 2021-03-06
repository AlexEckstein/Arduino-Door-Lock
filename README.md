# Arduino Door Lock
## Intro
The goal of this project was to create a basic design that will use a matrix to unlock a door with a servo. The servo can be activated by entering the correct key into the keypad. In order to keep the power requirement down so that the 12V supply is not necessary, I decided to use a lock that uses minimal resistance so that I could use a smaller servo. 
## Hardware
For this project I used a micro servo with a 9 gram weight capacity. A basic lock was also used. To keep the design simple, I decided to use the smaller one to lower my power requirements. I wanted to use a 4x4 matrix keypad so that I could bind F4 to an asterisk. This would help me use that symbol to authenticate password inputs. Different keypads may use different symbols. It really does not matter what you use as long as you know which button is the asterisk or change that symbol in the code. 
## Schematic
![Schematic](https://github.com/AlexEckstein/Arduino-Door-Lock/blob/master/Door%20Lock_schem.jpg)
