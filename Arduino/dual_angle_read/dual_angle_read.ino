// used a library because i'm a lazy piece of shit
#include <ams_as5048b.h>

//unit consts
#define U_RAW 1
#define U_TRN 2
#define U_DEG 3
#define U_RAD 4
#define U_GRAD 5
#define U_MOA 6
#define U_SOA 7
#define U_MILNATO 8
#define U_MILSE 9
#define U_MILRU 10

AMS_AS5048B sensorA(0x41); // 3.61x
AMS_AS5048B sensorB(0x42); // 3.53x

#define MAX_D 8192
#define MIN_D -8192

#define BUFFER 5000

int16_t encoder_a = 0;
int16_t encoder_b = 0;
int16_t encoder_delta = 0;
int16_t delta_alt = 0;

void setup() {

  //Start serial
  Serial.begin(9600);
  while (!Serial) ; //wait until Serial ready

  //init AMS_AS5048B object
  sensorA.begin();
  sensorB.begin();


  //  sensorA.setZeroReg();
  //  sensorB.setZeroReg();

}

void loop() {

  encoder_a = sensorA.angleRegR();
  encoder_b = sensorB.angleRegR();

  encoder_delta = encoder_a - encoder_b;

  if ((encoder_a > encoder_b) & (encoder_delta > 0)){
    delta_alt = encoder_a - (encoder_b + 16384);
  }
  if ((encoder_a < encoder_b) & (encoder_delta < 0)){
    delta_alt = (encoder_a + 16384) - encoder_b;
  }

  // positive spikes in the negative dir, and negative spikes in the positive dir
  // if (a > b), diff, 

  // calculate rollover count from diff?

  Serial.print(encoder_a);
  Serial.print(",");
  Serial.print(encoder_b);
  Serial.print(",");
  Serial.print(encoder_delta);
  Serial.print(",");
  Serial.print(delta_alt);
  Serial.print(",");
  Serial.print(encoder_delta+delta_alt);
  
  Serial.println();

}
