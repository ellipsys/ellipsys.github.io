#include <Servo.h>
char recibida = 0;
Servo servoMotor;
const int trigPin = 7;
const int echoPin = 8;

void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //motor avanza
  pinMode(12, OUTPUT);    //motor retrocede
  servoMotor.attach(11);//pin señal servo
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}
/*
 1  go
 2  derecha
 3  izquierda
 4  atras
 */
int ping(int trigPin, int echoPin)
        {   long duracion, distancia ;
            digitalWrite(trigPin, LOW);        // Nos aseguramos de que el trigger está desactivado
            delayMicroseconds(2);              // Para asegurarnos de que el trigger esta LOW
            digitalWrite(trigPin, HIGH);       // Activamos el pulso de salida
            delayMicroseconds(10);             // Esperamos 10µs. El pulso sigue active este tiempo
            digitalWrite(trigPin, LOW);        // Cortamos el pulso y a esperar el echo
            duracion = pulseIn(echoPin, HIGH) ;
            distancia = duracion / 2 / 29.1  ;
            return distancia;
        }
void loop()
{
  if(Serial.available() > 0)  
  
  {
    int cm = ping(trigPin, echoPin);
    Serial.print(cm);
    Serial.print("\n");
    recibida = Serial.read();      //lee los valores recibidos desde la app con los  botones 
    while (cm > 10){
      if (recibida == '1'){
        Serial.print("Dato recibido: ADELANTE");
        Serial.print("\n");
        digitalWrite(13, LOW);
        servoMotor.write(90);
        delay(1000);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        delay(1000);
        digitalWrite(13, LOW);
      
      
    }
     else if (recibida == '2'){
      String var = "derecha";
      Serial.print("Dato recibido: DERECHA");
      Serial.print("\n");
      servoMotor.write(0);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      delay(1000);
      servoMotor.write(90);
      digitalWrite(13, LOW);
      
     }
      else if (recibida == '3'){
        
        Serial.print("Dato recibido: IZQUIERDA");
        Serial.print("\n");
        servoMotor.write(180);
        delay(1000);
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        delay(1000);
        servoMotor.write(90);
        digitalWrite(13, LOW);
      }
      else if (recibida == '4'){
        
        Serial.print("Dato recibido: ATRAS");
        Serial.print("\n");
        digitalWrite(13, LOW);
        servoMotor.write(90);
        delay(1000);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        delay(1000);
        
    }
      }
    
    }    
}
