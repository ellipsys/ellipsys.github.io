#include <Servo.h>
char recibida = 0;
Servo servoMotor;
const int trigPin = 53; //SENSOR DE DISTANCIA
const int echoPin = 52;
int LeftPin=28; //Pines de salida del Arduino
int RightPin=29;//////MOTOR

void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(LeftPin, OUTPUT);
  pinMode(RightPin, OUTPUT);
  servoMotor.attach(50);//pin señal servo
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.print("I AM READY\n");
  
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
void alto(){
  digitalWrite(LeftPin, LOW);
  digitalWrite(RightPin, LOW);
        
  
  }

void loop()
{ 
  int cm = ping(trigPin, echoPin);
  
  
  if(Serial.available() > 0)  
  
  {
    
    
    //Serial.print("Distancia en centimetros: "+ String(cm)+"\n");
    recibida = Serial.read();      //lee los valores recibidos desde la app con los  botones 
    
    if (cm > 10){
      if (recibida == '1'){
        Serial.print("Dato recibido: ADELANTE");
        Serial.print("\n");
        Serial.print(String(cm)+"CM\n##############################################\n");
        servoMotor.write(90);
        delay(1000);
        digitalWrite(LeftPin, LOW);
        delay(1000);
        digitalWrite(RightPin, HIGH);
        delay(1000);
        alto();
    }
    if (recibida == '2'){
        Serial.print("Dato recibido: DERECHA");
        Serial.print("\n");
        Serial.print(String(cm)+"CM\n##############################################\n");
        servoMotor.write(180);
        digitalWrite(LeftPin, LOW);
        delay(1000);
        digitalWrite(RightPin, HIGH);
        delay(1000);
        servoMotor.write(90);
        alto();
    }
    if (recibida == '3'){
        Serial.print("Dato recibido: IZQUIERDA");
        Serial.print("\n");
        Serial.print(String(cm)+"CM\n##############################################\n");
        servoMotor.write(0);
        digitalWrite(LeftPin, LOW);
        delay(1000);
        digitalWrite(RightPin, HIGH);
        delay(1000);
        servoMotor.write(90);
        alto();
    }
    if (recibida == '4'){
        Serial.print("Dato recibido: ATRAS");
        Serial.print("\n");
        Serial.print(String(cm)+"CM\n##############################################\n");
        servoMotor.write(90);
        digitalWrite(LeftPin, HIGH);
        delay(1000);
        digitalWrite(RightPin, LOW);
        delay(1000);
        alto();
    }
    
      }
    else{
      Serial.print("#####################STOP#######################\n");
      Serial.print(String(cm)+"CM\n##############################################\n");
      Serial.print("NO SE PUEDE AVANZAR\n");
      alto();
      }
    
      
      }
    
       
} 
