#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{

Serial.begin(9600);

pinMode (13, OUTPUT);                       //The Relais is on pin 13.

digitalWrite(13, LOW);                      //Make sure the Relais is turned off.

irrecv.enableIRIn();

}

void loop() {

if (irrecv.decode(&results)) {

Serial.println(results.value, DEC);         //The received code will be printed on the serial monitor.

if (results.value == 16724175)              //The relais will be turned on if the receiver receives the code "16724175"

{digitalWrite (13, HIGH);}                  //The relais is turned on.

delay(500);                                 //The relais stays on for 500ms.

{digitalWrite (13, LOW);}                   //The relais is turned off.


irrecv.resume();

}

}
