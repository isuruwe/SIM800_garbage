//For more Information visit www.aeq-web.com?ref=arduinoide

#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial mySerial(10, 11);            // RX, TX Pins
String apn = "dialogbb";                       //APN
String apn_u = "";                     //APN-Username
String apn_p = "";                     //APN-Password
String url = "http://203.115.24.227:8888";  //URL for HTTP-POST-REQUEST
String name1;   //String for the first Paramter (e.g. Sensor1)
String description;   //String for the second Paramter (e.g. Sensor2)



void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  delay(10000);
}

void loop() { // run over and over

  
    name1 = "123";
    description = "ABC";
    gsm_sendhttp(); //Start the GSM-Modul and start the transmisson
    delay(10000); //Wait one minute

}


void gsm_sendhttp() {
  
  
 
  mySerial.println("AT");
  runsl();//Print GSM Status an the Serial Output;
   Serial.println("1");
  delay(5000);
 
 mySerial.println("AT+CMEE=2");
    runsl();
 // mySerial.println("AT+CBAND=EGSM_DCS_MODE");
    //runsl();
   // delay(100);
  mySerial.println("AT+CBAND=EGSM_PCS_BAND");
    runsl();
    delay(5000);
mySerial.println("AT+CPIN?");
  runsl();
   Serial.println("6");
  delay(100);
 
  mySerial.println("AT+CREG=1");
  runsl();
   Serial.println("6");
  delay(100);
  mySerial.println(" AT+CREG?");
  runsl();
   Serial.println("6");
  delay(100);
  
  mySerial.println("AT+CGATT?");
  runsl();
   Serial.println("6");
  delay(100);
  
   mySerial.println("AT+CSQ");
  runsl();
   Serial.println("6");
  delay(100);
  mySerial.println("AT+SAPBR=3,1,Contype,GPRS");
  runsl();
   Serial.println("2");
  delay(100);
  mySerial.println("AT+SAPBR=3,1,APN," + apn);
  runsl();
   Serial.println("3");
  delay(100);
 // mySerial.println("AT+SAPBR=3,1,USER," + apn_u); //Comment out, if you need username
//  runsl();
  // Serial.println("4");
 // delay(100);
  //mySerial.println("AT+SAPBR=3,1,PWD," + apn_p); //Comment out, if you need password
 // runsl();
//   Serial.println("5");
//  delay(100);
 
 
  mySerial.println("AT+SAPBR =1,1");
  runsl();
   Serial.println("6");
  delay(100);
  mySerial.println("AT+SAPBR=2,1");
  runsl();
  delay(2000);

  
  mySerial.println("AT+HTTPINIT");
  runsl();
   Serial.println("8");
  delay(100);
  mySerial.println("AT+HTTPPARA=CID,1");
  runsl();
   Serial.println("9");
  delay(100);
  mySerial.println("AT+HTTPPARA=URL," + url);
  runsl();
    Serial.println("10");
  delay(100);
 // mySerial.println("AT+HTTPPARA=CONTENT,application/x-www-form-urlencoded");
 //  mySerial.println("AT+HTTPPARA=name="+ String(name1) + "&description=" + String(description) +"");
// mySerial.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");  
 //mySerial.println("AT+HTTPPARA?");  
 // runsl();
 //  Serial.println("11");
//  delay(100);
 // mySerial.println("AT+HTTPDATA=19,10000");
//  runsl();
   // Serial.println("12");
 // delay(100);
//mySerial.println("name=" + name1 + "&description=" + description);
 runsl();
   Serial.println("13");
  delay(1000);
  mySerial.println("AT+HTTPACTION=0");
  runsl();
    Serial.println("14");
  delay(10000);
  mySerial.println("AT+HTTPREAD");
  runsl();
    Serial.println("15");
  delay(100);
  mySerial.println("AT+HTTPTERM");
  runsl(); 
    Serial.println("16");
}

//Print GSM Status
void runsl() {
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }

}







