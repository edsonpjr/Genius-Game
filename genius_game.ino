// This is a Genius game simulator

#define LED_RED 2
#define LED_GREEN 3
#define LED_YELLOW 4
#define LED_BLUE 5
#define BUTTON_RED 8
#define BUTTON_GREEN 9
#define BUTTON_YELLOW 10
#define BUTTON_BLUE 11

#define SEQUENCE_LENGTH 4
#define SECOND 1000 // == 1000 millisecond(s)

int ledSequence[SEQUENCE_LENGTH];

enum States {
  READY_NEXT_ROUND, 
  USER_ANSWERING, 
  WIN, 
  GAME_OVER
};

int level = 0;
int answeredLeds = 0;


void setup(){
	Serial.begin(9600);
	setPorts();
	setSequence(); 
}

void loop() {
  switch (currentGameState()) {
  	case READY_NEXT_ROUND:
      	Serial.println("Ready for the next round");
		startRound();
      	break;
    case USER_ANSWERING:
      	Serial.println("User answering");
        checkUserAnswer();
      	break;
    case WIN:
      	Serial.println("Winner");
        winBlink();
      	break;
    case GAME_OVER:
	Serial.println("Game Over");
    	gameOverBlink();
      	break;
  }
  delay(SECOND/2);

}

void startRound(){
  level++;
  answeredLeds = 0;
  if(level <= SEQUENCE_LENGTH)
    blinkRoundLeds();
}

int currentGameState(){
  if(level <= SEQUENCE_LENGTH){
    if(answeredLeds == level){
      return READY_NEXT_ROUND;
    }else{
      return USER_ANSWERING;
    }
  }else if(level == SEQUENCE_LENGTH + 1){ 
    return WIN;
  }else{ 
    return GAME_OVER;
  }
}

void checkUserAnswer(){
  int answer = isButtonPressed();

  if(answer == -1){
    return;
  }

  if(answer == ledSequence[answeredLeds]){
    answeredLeds++;
  }else{
    level = SEQUENCE_LENGTH + 2; 
  }
}

void blinkRoundLeds(){
  for(int i = 0; i < level; i++){
    blinkLed(ledSequence[i]);
  }
}
  	
void blinkLed(int port){
  digitalWrite(port,HIGH);
  delay(SECOND);
  digitalWrite(port,LOW);
  delay(SECOND/2); 
}

void setPorts(){
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);

}

void setSequence(){
  randomSeed(analogRead(0)); // Seeds the random number generator based on the analog reading from pin 0
    for(int i = 0; i < SEQUENCE_LENGTH; i++){
      ledSequence[i] = pickLed();
    }
}

int pickLed(){
  return random(LED_RED, LED_BLUE + 1);
}

void winBlink() {
  blinkLed(LED_GREEN);
  blinkLed(LED_YELLOW);
  blinkLed(LED_RED);
  blinkLed(LED_BLUE);
  delay(SECOND/2);
}

void gameOverBlink(){
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  delay(SECOND/10);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  delay(SECOND/10);
}

int isButtonPressed(){
  if(digitalRead(BUTTON_GREEN) == LOW) {
    blinkLed(LED_GREEN); // make sure the button was pressed and read
    return LED_GREEN;  
  }
  if(digitalRead(BUTTON_YELLOW) == LOW) {
    blinkLed(LED_YELLOW); // make sure the button was pressed and read
    return LED_YELLOW;  
  }
  if(digitalRead(BUTTON_RED) == LOW) {
    blinkLed(LED_RED); // make sure the button was pressed and read
    return LED_RED;  
  }
  if(digitalRead(BUTTON_BLUE) == LOW) {
    blinkLed(LED_BLUE); // make sure the button was pressed and read
    return LED_BLUE;  
  }
  	
  return -1; // None of the buttons were pressed
}
