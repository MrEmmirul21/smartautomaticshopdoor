int greenLED = 4;
int redLED = 2;
int entryButton = 13;
int exitButton = 12;
int customerCount;
int customerLimit = 5;

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(entryButton, INPUT_PULLUP);
  pinMode(exitButton, INPUT_PULLUP);
  
  // initialize the LED pin as an output:
  pinMode(greenLED, OUTPUT);     // green light
  pinMode(redLED, OUTPUT);       // red light
}

void loop()
{   
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  if(digitalRead(entryButton) == HIGH)
  {
    
    //If current customer count is greater or equal to max allowance, turn on the red LED.
    if(customerCount > customerLimit)
    {
      digitalWrite(4, LOW);
      digitalWrite(2, HIGH);
    }
    //If current customer count is lower or equal to max allowance, turn on the green LED.
    else
    {
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      customerCount++;
      Serial.println("- 1 customer enter the shop");
      //Serial.println(customerCount);
      delay(2000);
    }
    
  }

  else if(digitalRead(exitButton) == HIGH)
  {
    Serial.println(digitalRead(exitButton));
    customerCount--;
    Serial.println("- 1 customer left the shop");
    //Serial.println(customerCount);
    delay(2000);
  }
  Serial.println(customerCount);
}
