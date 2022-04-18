#include "LedControl.h"
#include "functions.h"

#define DATA_IN_PIN 11
#define CLOCK_PIN 10
#define CS_PIN 9
#define DEVICE_COUNT 1

// initializat led control object
LedControl lc=LedControl(
  DATA_IN_PIN,
  CLOCK_PIN,
  CS_PIN,
  DEVICE_COUNT
);


unsigned long delaytime=75;

int intensities[14]={1,2,3,4,5,6,7,8,9,10,11,12,13,14};

void setup() {

  Serial.begin(9600);
  int c = lc.getDeviceCount();
  Serial.print(c);

  // configure max 1
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);// clear screen
//  lc.clearDisplay(1);// clear screen

}



void loop() {
  // lc.clearDisplay(0);// clear screen

  // for (int i=0; i<6; i++){
  //   for (int j=0; j<6; j++){
  //     lc.setLed(0,i,j, true); //
  //       delay(100);
  //   }
  // }

  // for (int i=0; i<6; i++){
  //   for (int j=0; j<6; j++){
  //     lc.setLed(0,i,j, false); //
  //     delay(100);
  //   }
  // }

  Serial.println("Start the matix1");
  the_matrix_animation(lc, 1, 1);
  // lc.clearDisplay(0);


}
