int entryButton = 13;
int exitButton = 12;
int entrybuttonState = 0;
int lastentryButtonState = 0;
int exitbuttonState = 0;
int lastexitButtonState = 0;
int customerCount = 0;
int customerLimit = 5;
int no=0;

void setup() {
  Serial.begin(9600);

  pinMode(entryButton, INPUT_PULLUP);
  pinMode(exitButton, INPUT_PULLUP);
  
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop()
{
  entrybuttonState = digitalRead(entryButton);
  exitbuttonState = digitalRead(exitButton);
    
  if(entrybuttonState != lastentryButtonState)
  {
    if(entrybuttonState == HIGH)
    {
      if(customerCount >= customerLimit)
      {
        digitalWrite(4, LOW);
        digitalWrite(2, HIGH);
        tone(8, 1000, 2000);
        
        digitalWrite(4,LOW);
        digitalWrite(2,LOW);
      }
      else
      {
        digitalWrite(4, HIGH);
        digitalWrite(2, LOW);
        customerCount += 1;

        Serial.print("\n A customer ENTER the shop, total customers: ");
        Serial.println(customerCount);
        delay(1000);
        digitalWrite(4,LOW);
        digitalWrite(2,LOW);
      }
    }
  }
  entrybuttonState = lastentryButtonState;
    
  if(exitbuttonState != lastexitButtonState)
  {
    if(exitbuttonState == HIGH && customerCount > 0)
    {
      digitalWrite(4,LOW);
      digitalWrite(2,LOW);      
      customerCount--;
      Serial.print("\n A customer LEFT the shop, remaining customers: ");
      Serial.println(customerCount);
      delay(1000);
    }        
  }
  exitbuttonState = lastexitButtonState;
  Serial.println(customerCount);
}
