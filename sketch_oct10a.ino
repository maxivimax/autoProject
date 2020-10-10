#include "IRremote.h"

IRrecv irrecv(7); // указываем вывод, к которому подключен приемник

decode_results results;

void setup() {
  Serial.begin(9600); // выставляем скорость COM порта
  irrecv.enableIRIn(); // запускаем прием
}

void loop() {
  if ( irrecv.decode( &results )) {
    Serial.println(results.value, HEX);// если данные пришли
    switch ( results.value ) {
    case 0x1689609F:
        Serial.println( "1" );
        break;
    case 0x1689B847:
        Serial.println( "2" );
        break;
    }    
    irrecv.resume(); // принимаем следующую команду
  }
}
