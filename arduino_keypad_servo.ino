#include <Password.h> //http://playground.arduino.cc/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip  
#include <Servo.h>

//declares servo
Servo myservo; 
//password to unlock
Password password = Password( "3847" ); 

const byte ROWS = 4; 
const byte COLS = 4; 

// Define the Keymapping for keypad
char keys[ROWS][COLS] = {
  {'1','2','3','$'},
  {'4','5','6','%'},
  {'7','8','9','@'},
  {'*','0','#','*'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 6, 8, 7, 2 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3, 9 }; 
// Initialize the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.write(254);
  Serial.write(0x01);
  //delay to prevent any problems with attaching servo
  delay(200);
  //servo on digital pin 13
  myservo.attach(13); 
  keypad.addEventListener(keypadEvent);
}

void loop(){
  //Saves input to memory
  keypad.getKey();
  //makes sure servo is at 0 degrees to lock
  myservo.write(0);  
}
  
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
  case PRESSED:
  
  Serial.print("Enter:");
  Serial.println(eKey);
  delay(10);
  Serial.write(254);
  
	switch (eKey){
		case '*': checkPassword(); delay(1); 
		break;
		
		default: password.append(eKey); delay(1);
		}
	}
}

void checkPassword(){  
if (password.evaluate()){
    Serial.println("Accepted");
    Serial.write(254);delay(10);
	//degrees the servo will orientate itself to unlock
    myservo.write(150); 
}else{
    Serial.println("Denied");
    Serial.write(254);delay(10);
	//Makes the servo lock when wrong password is entered
    myservo.write(0);
	}
}
