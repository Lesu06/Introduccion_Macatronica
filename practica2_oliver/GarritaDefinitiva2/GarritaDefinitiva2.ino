#include <Servo.h>;

Servo motor1; // DECLARAR SERVOS
Servo motor2;
Servo motor3;
Servo motor4;
int valorX = 0; // LECTURA DEL EJE X
int valorX2 = 0; // LECTURA DEL EJE X 2
int valorY = 0; // LECTURA DEL EJE Y
int valorY2 = 0; // LECTURA DEL EJE Y 2
int pinJX = A1; // PIN ANALOGICO A0 DEL EJE X
int pinJY = A2; // PIN ANALOGICO A1 DEL EJE Y
int pinJX2 = A3; // PIN ANALOGICO A0 DEL EJE X 2
int pinJY2 = A4; // PIN ANALOGICO A1 DEL EJE Y
int grados1 = 50; // GRADOS DEL SERVO 1
int grados2 = 50; // GRADOS DEL SERVO 2
int grados3 = 90; // GRADOS DEL SERVO 3
int grados4 = 50; // GRADOS DEL SERVO 4
int salto = 0; 

void setup() {
 Serial.begin(9600); // ACTIVA LA COMUNICACIÓN CON LA PLACA

 motor1.attach (3); // PIN DIGITAL PWM 5 DONDE ESTÁ CONECTADO EL SERVO 1

 motor2.attach (6); // PIN DIGITAL PWM 10 DONDE ESTÁ CONECTADO EL SERVO 2

 motor3.attach (9);

 motor4.attach (10);
 }

void loop() {
  valorX = analogRead(pinJX);  // Leemos la entrada del joystick
  valorX = constrain(valorX, 0, 1024);  // Evitamos que el valor del ejeX se salga de estos parámetros
  grados1 = constrain(grados1, 0, 80); //pata latelar
  valorY = analogRead(pinJY);  // Leemos la entrada del joystick
  valorY = constrain(valorY, 100, 900);  // Evitamos que el valor del ejeX se salga de estos parámetros
  grados2 = constrain(grados2, 50, 135); // garra
  valorX2 = analogRead(pinJX2);  // Leemos la entrada del joystick
  valorX2 = constrain(valorX2, 0, 1024);  // Evitamos que el valor del ejeX se salga de estos parámetros
  grados3 = constrain(grados3, 0, 180); 
  valorY2 = analogRead(pinJY2);  // Leemos la entrada del joystick
  valorY2 = constrain(valorY2, 0, 1024);  // Evitamos que el valor del ejeX se salga de estos parámetros
  grados4 = constrain(grados4, 50, 180);  // Evitamos que el ángulo se salga de estos parámetros // Evitamos que el ángulo se salga de estos parámetros

   if (valorX > 505 && valorX < 520) {
    motor1.write(grados1) ; 
  }  
  else if (valorX < 505) {
    if (valorX > 100) {salto = 1;}
    else if (valorX > 50) {salto = 2;}
    else if (valorX > 5) {salto = 3;}
    else {salto = 5;}
    grados1 -= salto;  // Disminuimos el ángulo
    motor1.write(grados1) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Menos ángulo");
  }
  // Controla el aumento del ángulo dependiendo de cuánto accionemos el joystick
  else if (valorX > 520) {
    if (valorX < 900) {salto = 1;}
    else if (valorX < 1000) {salto = 2;}
    else if (valorX < 1020) {salto = 3;}
    else {salto = 5;}
    grados1 += salto;  // Aumentamos el ángulo
    motor1.write(grados1) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Más ángulo");  
  }
   if (valorY > 505 && valorY < 520) {
    motor2.write(grados2) ; 
  }  
  else if (valorY < 505) {
    if (valorY > 100) {salto = 1;}
    else if (valorY > 50) {salto = 2;}
    else if (valorY > 5) {salto = 3;}
    else {salto = 5;}
    grados2 -= salto;  // Disminuimos el ángulo
    motor2.write(grados2) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Menos ángulo");
  }
  // Controla el aumento del ángulo dependiendo de cuánto accionemos el joystick
  else if (valorY > 520) {
    if (valorY < 900) {salto = 1;}
    else if (valorY < 1000) {salto = 2;}
    else if (valorY < 1020) {salto = 3;}
    else {salto = 5;}
    grados2 += salto;  // Aumentamos el ángulo
    motor2.write(grados2) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Más ángulo");
  }
  // Parte 2 aqui
   if (valorY2 > 505 && valorY2 < 520) {
    motor3.write(grados3) ; 
  }  
  else if (valorY2 < 505) {
    if (valorY2 > 100) {salto = 1;}
    else if (valorY2 > 50) {salto = 2;}
    else if (valorY2 > 5) {salto = 3;}
    else {salto = 5;}
    grados3 -= salto;  // Disminuimos el ángulo
    motor3.write(grados3) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Menos ángulo");
  }
  // Controla el aumento del ángulo dependiendo de cuánto accionemos el joystick
  else if (valorY2 > 520) {
    if (valorY2 < 900) {salto = 1;}
    else if (valorY2 < 1000) {salto = 2;}
    else if (valorY2 < 1020) {salto = 3;}
    else {salto = 5;}
    grados3 += salto;  // Aumentamos el ángulo
    motor3.write(grados3) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Más ángulo");
  }
     if (valorX2 > 505 && valorX2 < 520) {
    motor4.write(grados4) ; 
  }  
  else if (valorX2 < 505) {
    if (valorX2 > 100) {salto = 1;}
    else if (valorX2 > 50) {salto = 2;}
    else if (valorX2 > 5) {salto = 3;}
    else {salto = 5;}
    grados4 -= salto;  // Disminuimos el ángulo
    motor4.write(grados4) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Menos ángulo");
  }
  // Controla el aumento del ángulo dependiendo de cuánto accionemos el joystick
  else if (valorX2 > 520) {
    if (valorX2 < 900) {salto = 1;}
    else if (valorX2 < 1000) {salto = 2;}
    else if (valorX2 < 1020) {salto = 3;}
    else {salto = 5;}
    grados4 += salto;  // Aumentamos el ángulo
    motor4.write(grados4) ;  // Le indicamos a cuántos grados se tiene que poner el servo
    //Serial.println("Más ángulo");
  }
delay (20);
}