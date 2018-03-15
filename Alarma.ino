/*Instituto Tecnologio de Leon
 Ingenieria en Sistemas Computacionales
 Sistemas Programables
 Autor: Canencia Rodriguez Aurora Denysse
 Nombre: Simulacion de una alarma con arduino
 Descripcion: Practica de arduino en donde se implementa el funcionamiento de una alarma
 utilizando un reed switch, un buzzer, un led y un iman. 
 Cuando el iman se encuentre cerca del reed switch la alarma estara desactivada,
 pero al quitarlo la alarma se activara logrando que parpade un led y que el buzzer suene.
 Ademas se implemento un ahorro de energia en el arudino "poniendolo a dormir", esto utilizando
 una interrupcion. 
 Fecha: 15/03/2018*/
 
#include <avr/sleep.h>//Incluimos la libreria para AVR sleep.

//Declara las variables que se van a utilizar
int led =10;  //Led que indicara cuando se active la alarma 
int reedsw=2; //Pin del reed switch
int buzzer=8; //Pin del buzzeer
int val=0;    //Variable qe guardara el estado del reed switch

// Se ejecuta cada el arduino se inicia 
void setup() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  //Establecemos el modo de bajo consumo.
  attachInterrupt(0,interrupt,LOW);     //Establecemos la interrupcion para poder reactivarlo.
  
  pinMode(led,OUTPUT);                //Declaramos el led como salida 
  pinMode(reedsw,INPUT);              //Declaramos el reedswitch como entrada
  pinMode(buzzer,OUTPUT);             //Declaramos el buzzer como salida
}                                     //Fin del setup()

//Esta funcion se mantiene ejeutandose mientras se este energizando el arduino
void loop() {
  sleep_enable(); //inicializamos el modo bajo consumo

  sleep_mode();//ponemos el modo bajo consumo
  digitalWrite(13,!digitalRead(13));//SI se desactiva el modo bajo consumo se enciende/apaga el led
  
  val=digitalRead(reedsw);         //lee el valor en  el reedswitch
  if(val==LOW){                    //Si el valor es bajo(el iman se aleja del reed switch)
  digitalWrite(led,HIGH);          //Enciende el led
  digitalWrite(buzzer,HIGH);       //Suena el buzzer
  delay(1000);                     //Espera un tiempo de un segundo
  digitalWrite(led,LOW);           //Apaga el led
  digitalWrite(buzzer,LOW);        //El buzzer deja de sonar
  delay(1000);                     //Espera un tiempo de un segundo 
  } else{                          //Si no se sumple la condicion (el iman esta cerca)
    digitalWrite(led,LOW);         //Apaga el Led
    digitalWrite(buzzer,LOW);      //El buzzer deja de sonar
  }                                //fin del else
}                                  //fin del loop()

void interrupt(){                 //funcion que maneja la interrupcion
  sleep_disable();                //desactivamos el modo bajo consumo
}                                 //Fin de la interrupcion 
                                  //Fin del programa 

