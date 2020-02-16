/*
  1 Digital 8-Segment LED Display
  Display the number from 1-9
*/
byte Digital[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};//the character code for number 0-9
String readString;

void setup()

{
  Serial.begin(9600);
  Serial.setTimeout(10);
  int i=2;
  for(i=2;i<10;i++)
  {
   pinMode(i,OUTPUT);
   digitalWrite(i,HIGH);
  }
}
void loop()
{
  int i;

  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
    i = readString.toInt();  //convert readString into a number
    readString = "";
  }
  
  int j;
  //Display number i by sending the character code to the digital pin
    for(j=0;j<8;j++)
   {  
    if(Digital[i]&1<<j)
    digitalWrite(9-j,LOW);
    else
    digitalWrite(9-j,HIGH);
    }
    delay(500);
}
