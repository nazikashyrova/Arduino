
#include <Stepper.h>

const int stepRev = 360;//motorun bir tam dönüşü tamamlaması için gereken adım sayısı

Stepper Stepper1(stepRev, 8, 9, 10, 11);//horizontal stepper
 
Stepper Stepper2(stepRev, 7, 6, 5, 4);//vertical stepper

Stepper Stepper3(stepRev, 3, 2, 1, 0);//ratation stepper

int currentPosition1 = 0; // Current position of Stepper1
int currentPosition2 = 0; // Current position of Stepper2
int currentPosition3 = 0; // Current position of Stepper3

void setup()
{
  Serial.begin(9600);
}

void loop() {
  Serial.println("Motoru sec: H (yatay), V (dikey), R (donme)");

  while (!Serial.available()) {
    // Kullanıcının giriş yapmasını bekleme
  }

  char motorChoice = Serial.read();

  if (motorChoice == 'H' || motorChoice == 'V' || motorChoice == 'R') {
    Serial.println("Kac cm/derece hareket etsin?(yatay 0-25), V (dikey 0-15), R (donme 0-45)");

    while (!Serial.available()) {
      // Kullanıcının giriş yapmasını bekleme
    }

    int step = Serial.parseInt();

    switch (motorChoice) {
      case 'H':
        if (step >= 0 && step <= 25) {
          Serial.print("H");
          Serial.println(step);
   
  		  Stepper1.step(step);
		  currentPosition1 += step;
          Serial.print("Current Position of Stepper1: ");
          Serial.println(currentPosition1); 	
  		  Serial.println("Tamamlandi");
          
        } else {
          Serial.println("Hatali giris! 0 ile 25 arasinda bir deger giriniz.");
        }
        break;
      case 'V':
        if (step >= 0 && step <= 15) {
          Serial.print("V");
          Serial.println(step);
          
          Stepper2.step(step/2); //1 derece = 2 cm olduğu için
          currentPosition2 += step;
          Serial.print("Current Position of Stepper2: ");
          Serial.println(currentPosition2); 
          Serial.println("Tamamlandi");
        } else {
          Serial.println("Hatali giris! 0 ile 15 arasinda bir deger giriniz.");
        }
        break;
      case 'R':
        if (step >= 0 && step <= 45) {
          Serial.print("R");
          Serial.println(step);
          
          Stepper3.step(step);
          currentPosition3 += step;
          Serial.print("Current Position of Stepper3: ");
          Serial.println(currentPosition3); 
          Serial.println("Tamamlandi");
        } else {
          Serial.println("Hatali giris! 0 ile 45 arasinda bir deger giriniz.");
        }
        break;
    }
  } else {
    Serial.println("Hatalı motor seçimi! H, V veya R giriniz.");
  }
}
