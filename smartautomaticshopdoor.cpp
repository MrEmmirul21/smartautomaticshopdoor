int greenLED = 4;
int redLED = 2;
int entryButton = 12;
int exitButton = 13;
int entrybuttonState = 0;
int lastentryButtonState = 0;
int exitbuttonState = 0;
int lastexitButtonState = 0;
int customerCount = 0;
int customerLimit = 5;

void setup() {
  Serial.begin(9600);

  pinMode(entryButton, INPUT_PULLUP);
  pinMode(exitButton, INPUT_PULLUP);
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop()
{
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  entrybuttonState = digitalRead(entryButton);
  exitbuttonState = digitalRead(exitButton);
    
  if(entrybuttonState != lastentryButtonState)
  {
    if(entrybuttonState == HIGH)
    {
      if(customerCount >= customerLimit)
      {
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
      }
      else
      {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        customerCount += 1;
        Serial.println("- 1 customer enter the shop, remaining customers:");
        //Serial.println(customerCount);
        delay(2000);
      }
    
    }
  }
  entrybuttonState = lastentryButtonState;
    
  if(exitbuttonState != lastexitButtonState)
  {
    if(digitalRead(exitButton) == HIGH)
    {
      Serial.println(digitalRead(exitButton));
      customerCount--;
      Serial.println("- 1 customer left the shop, remaining customers:");
      //Serial.println(customerCount);
      delay(2000);
    }        
  }
  exitbuttonState != lastexitButtonState;
  Serial.println(customerCount);
}
