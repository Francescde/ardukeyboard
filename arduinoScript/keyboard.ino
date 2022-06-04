/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground through 220 ohm resistor (or use the
    built-in LED on most Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
*/

// this constant won't change:
const int  buttonPinA = 2;    // the pin that the pushbutton is attached to
const int  buttonPinB = 2;
const int  buttonPinC = 2;
const int  buttonPinD = 2;

// Variables will change:
int buttonPushCounterA = 0;   // counter for the number of button presses
int buttonStateA = 0;         // current state of the button
int lastButtonStateA = 0;     // previous state of the button


int buttonPushCounterB = 0;   // counter for the number of button presses
int buttonStateB = 0;         // current state of the button
int lastButtonStateB = 0;     // previous state of the button

int buttonPushCounterC = 0;   // counter for the number of button presses
int buttonStateC = 0;         // current state of the button
int lastButtonStateC = 0;     // previous state of the button

int buttonPushCounterD = 0;   // counter for the number of button presses
int buttonStateD = 0;         // current state of the button
int lastButtonStateD = 0;     // previous state of the button



void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinD, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  // initialize serial communication:
  Serial.begin(9600);
  Serial.println("hola");
}

int pressOrRelease(int buttonState, int lastButtonState, int buttonPushCounter, char pressed){
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.println(pressed);
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
  }
  // save the current state as the last state, for next time through the loop
  return buttonState;
}


void loop() {
  // read the pushbutton input pin:
  buttonStateA = digitalRead(buttonPinA);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateC = digitalRead(buttonPinC);
  buttonStateD = digitalRead(buttonPinD);

  // save the current state as the last state, for next time through the loop
  lastButtonStateA = pressOrRelease(buttonStateA, lastButtonStateA, buttonPushCounterA, 'a');
  lastButtonStateB = pressOrRelease(buttonStateB, lastButtonStateB, buttonPushCounterB, 'b');
  lastButtonStateC = pressOrRelease(buttonStateC, lastButtonStateC, buttonPushCounterC, 'c');
  lastButtonStateD = pressOrRelease(buttonStateD, lastButtonStateD, buttonPushCounterD, 'd');
  
    // Delay a little bit to avoid bouncing
    delay(50);


}
