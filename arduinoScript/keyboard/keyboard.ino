// this constant defines ping position
const int  buttonPinA[4] = {4,5,6,7};    // the pin that the pushbutton is attached to

// Variables will change:
int buttonStateA[sizeof(buttonPinA)];         // current state of the button
int lastButtonStateA[sizeof(buttonPinA)];     // previous state of the button

void setup() {
  for (int i =0; i < sizeof(buttonPinA); ++i)
  {
    pinMode(buttonPinA[i], INPUT_PULLUP);
    buttonStateA[i] = HIGH;
    lastButtonStateA[i] = HIGH;
  }
  // initialize serial communication:
  Serial.begin(9600);
  Serial.println("Program started");
}

int pressOrRelease(int buttonState, int lastButtonState, String pressed){
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      Serial.print("on ");
      Serial.println(pressed);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.print("off ");
      Serial.println(pressed);
    }
  }
  // save the current state as the last state, for next time through the loop
  return buttonState;
}


void loop() {
  for (int i =0; i < sizeof(buttonPinA); ++i)
  {
    buttonStateA[i] = digitalRead(buttonPinA[i]);
    lastButtonStateA[i] = pressOrRelease(buttonStateA[i], lastButtonStateA[i], String(i));
  }
  //avoid overlay
  delay(50);
}
