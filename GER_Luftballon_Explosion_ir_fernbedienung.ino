#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{

Serial.begin(9600);

pinMode (13, OUTPUT);                       //An Pin 13 wird das Relais angeschlossen.

digitalWrite(13, LOW);                      //Dieses soll zunächst nicht geschaltet sein.

irrecv.enableIRIn();

}

void loop() {

if (irrecv.decode(&results)) {

Serial.println(results.value, DEC);         //Der empfangene Wert wird am seriellen Monitor ausgegeben.

if (results.value == 16724175)              //Wenn der Infrarotempfänger die Zahl 16724175 empfängt, soll das Relais geschaltet werden.

{digitalWrite (13, HIGH);}                  //Das Relais wird geschaltet.

delay(500);                                 //Das Relais bleibt für 500ms geschaltet.

{digitalWrite (13, LOW);}                   //Das Relais wird ausgeschaltet.


irrecv.resume();

}

}
