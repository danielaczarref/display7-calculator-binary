const int button = 12;
const int button2 = 13;
int counter = 0;


int MAX = 4;
int cont = 0;
int entrada1 = -1;  
int entrada2 = -1;
int resultado = 0;  


byte seven_seg_digits[11][7] = {
 { 0,0,0,0,0,0,1 },  
 { 1,0,0,1,1,1,1 },  
 { 0,0,1,0,0,1,0 },  
 { 0,0,0,0,1,1,0 },  
 { 1,0,0,1,1,0,0 },  
 { 0,1,0,0,1,0,0 },  
 { 0,1,0,0,0,0,0 },  
 { 0,0,0,1,1,1,1 },  
 { 0,0,0,0,0,0,0 },  
 { 0,0,0,1,1,0,0 },  
 { 1,1,1,1,1,1,1 }   
};
void setup(){
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(0, OUTPUT);
 
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(0 , 0);
  pinMode(button, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
   ligaSegmentosDisplay(10);

}

void ligaLed(int resultado){
  if(resultado == 0 ){
    digitalWrite(11, 0);
    digitalWrite(10, 0);
    digitalWrite(0 , 0);
  }else if(resultado == 1){
    digitalWrite(11, 0);
    digitalWrite(10, 0);
    digitalWrite(0 , 1);
  }
  else if(resultado == 2){
    digitalWrite(11, 0);
    digitalWrite(10, 1);
    digitalWrite(0 , 0);
  }
  else if(resultado == 3){
    digitalWrite(11, 0);
    digitalWrite(10, 1);
    digitalWrite(0 , 1);
  }
  else if(resultado == 4){
    digitalWrite(11, 1);
    digitalWrite(10, 0);
    digitalWrite(0 , 0);
  }
  else if(resultado == 5){
    digitalWrite(11, 1);
    digitalWrite(10, 0);
    digitalWrite(0 , 1);
  }
  else{
    digitalWrite(11, 1);
    digitalWrite(10, 1);
    digitalWrite(0 , 0);
  }
}

void ligaPonto(byte dot){  
  digitalWrite(9, dot);
}
void ligaSegmentosDisplay(byte digit){ 
  byte pino = 2;
 
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos){ 
    digitalWrite(pino, seven_seg_digits[digit][contadorSegmentos]); 
    ++pino;
  }
    ligaPonto(1); 
    delay(100); 
    ligaPonto(0); 
}

void loop() {
 
  if (digitalRead(button) == LOW && entrada1 == -1) {
    delay(300);
    counter++;
    if (counter == MAX) {
      counter = 0;
    }
    ligaSegmentosDisplay(counter);
   
  }


  if (digitalRead(button2) == LOW && entrada1 == -1) {
    delay(300);
    entrada1 = counter;

  }

  if (digitalRead(button) == LOW && entrada1 != -1 && entrada2 == -1) {
    delay(300);
    counter++;
    if (counter == MAX) {
      counter = 0;
    }
    ligaSegmentosDisplay(counter);
   

  }

  if (digitalRead(button2) == LOW && entrada1 != -1 && entrada2 == -1) {
      delay(300);
      entrada2 = counter;

      resultado = entrada1+entrada2;
      ligaSegmentosDisplay(resultado);
      ligaLed(resultado);

      counter = 0;
      entrada1 = -1;
      entrada2 = -1;

    }
}
