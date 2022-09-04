/*
                    Simply blink sketch 

                         ATTiny88
                     -----------------
               Pin  -|                |-  D2 PD2  INT0
               GND  -|                |-  D1 PD1  TXD
               5v   -|                |-  D0 PD0  LED RXD
    OC2B  PD3   D3  -|                |-  RST
          PD4   D4  -|                |-  D25 PC7
    OC0B  PD5   D5  -|                |-  D24 ADC5  SCL PC5
    AIN0  PD6   D6  -|                |-  D23 ADC4  SDA PC4
    AIN1  PD7   D7  -|                |-  D22 ADC3  PC3
          PB0   D8  -|                |-  D21 ADC2  PC2
    OC1A  PB1   D9  -|                |-  D20 ADC1  PC1
OC1B  SS  PB2   D10 -|                |-  D19 ADC0  PC0
    MOSI  PB3   D11 -|                |-  D18 ADC7  PA1
    MISO  PB4   D12 -|      -----     |-  D17 ADC6  PA0
     SCK  PB5   D13 -|     | USB |    |-  D16 PA3
          PB7   D14 -|     |     |    |-  D15 PA2
                      -----------------
 
 */

/************************* Defines ********************************/
#define DEBUG 0

#if DEBUG == 1
#define dprint(expression) Serial.print("# "); Serial.print( #expression ); Serial.print( ": " ); Serial.println( expression )
#define dshow(expression) Serial.println( expression )
#else
#define dprint(expression)
#define dshow(expression)
#endif

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif


/************************** Variables *****************************/
boolean flip = false;

/**************************  Functions ****************************/


/******************************************************************/
/*************************** Setup ********************************/
/******************************************************************/
void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  }

  


  /************************* Setup Pins ***************************/
  /* Pin D0 as OUTPUT for LED */
  DDRD |= _BV (0); 


}/**************************  End Setup **************************/


/******************************************************************/
/**************************** Loop ********************************/
/******************************************************************/
void loop() {
 flip = !flip;
 if(flip){
  PORTD |= _BV (0);
 }else{
  PORTD &= ~_BV (0);
 }

 delay(250);


}/*************************** End Loop *****************************/
