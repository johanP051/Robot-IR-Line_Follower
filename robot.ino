//#include <pitches.h>

// ROBOT IR SEGUIDOR DE LÍNEA

//Made by: Johan Posada
//Github: https://github.com/johanP051/

//Configurando LEDs
//int led1 = 4;
//int led2 = 3;

//Configirando pines puente H
int ENA = 11;
int IN1 = 10;
int IN2 = 9;
int IN3 = 8;
int IN4 = 7;
int ENB = 6;

//Configurando pines Sensores (ANALOG IN)
int Sensor1 = A0;
int Sensor4 = A3;

//Configurando velocidad de los motores
int SPEED = 200;


void setup() {

  //Se configuran los pines de salida al puente H
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  //Los sensores son entradas de información al Arduino, estos se van a usar después para activar los pines de salida al Puente H
  pinMode(Sensor1, INPUT);
  pinMode(Sensor4, INPUT);

  //Pin del Buzzer
  //pinMode(BUZZER_PIN, OUTPUT);

  //Estableciendo el monitor en serie con velocidad 9600 baudios
  //Serial.begin(9600);

}

void loop() {
  
  int ValS1 = digitalRead(Sensor1);
  int ValS4 = digitalRead(Sensor4);

  //LNegra = 0 (LOW); LBlanca = 1 (HIGH)

  /// (S2 y S3) en linea negra y (S1 y S4) en línea blanca
  if (ValS1 == HIGH && ValS4 == HIGH){
    mRight_Avanzar(SPEED);
    mLeft_Avanzar(SPEED);
  }

  ///Giro a la derecha
  else if (ValS1 == HIGH && ValS4 == LOW){
    mRight_Stop();
    mLeft_Avanzar(SPEED);
    
  }

  //Giro a la izquierda
  else if (ValS1 == LOW && ValS4 == HIGH){
    mLeft_Stop();
    mRight_Avanzar(SPEED);
  }
  else{
    Stop();
  }

}
void mRight_Avanzar(int speed){
  //Motor de la derecha
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
}

void mLeft_Avanzar(int speed){
  //Motor de la izquierda
  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void mRight_Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void mLeft_Stop(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Stop(){
  //Parando los dos motores
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
}
