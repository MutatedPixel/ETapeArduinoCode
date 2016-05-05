/*Do whatever you want with this code. I dont care.
 * 
 * Your wiring should look like this.
 * 
 *     Vin ---/\/\/\/-------/\/\/\/--- Gnd
 *              R1      |    Etape
 *                      |
 *                  Analog pin
 * 
 * 
 * 
 * 
 */






#define resistor_ohm 560 //R1 in your voltage divider.
#define analog_pin 0 //Which analog pin this is connected to on the arduino.
#define analog_ref 5.0 //According to the arduino website, The "top" voltage of your ADC. (Continues below)
//According to the arduino website 5v default on 5v arduino boards, and 3.3v on 3.3v arduino boards
#define full_resistance 545.82 //What resistance the etape is at when it is at it's top marker.
#define empty_resistance 3780.00 //What resistance the etape is at when no water is touching it.
#define etape_inches 12 //What size etape you use, in inches.

float Ratio;
float Resistance;

void setup() {
  Ratio = empty_resistance - full_resistance;
  Ratio = Ratio/etape_inches;
  Serial.begin(115200);
}
//Finds the resistance of the Etape.
float ReadResistance(int APIN, int RESISTOROHM, float AREF){
  float Resistance;
  float Voltage;
  int Reading;
  Reading = analogRead(APIN);
  Voltage = Reading*(AREF/1023);
  Resistance = AREF/Voltage; //This could probably be improved
  Resistance = Resistance - 1;
  Resistance = 1 / Resistance;
  Resistance = RESISTOROHM * Resistance;
  return Resistance;
}
//God this bit is horrible to look at. Finds how many inches the etape is at through magical ways. There's probably a better way to do this.
int FindInches(float RATIO, float RESISTANCE, float EMPTY, float FULL){
  int Inches;
//Comment out anything that is over the amount of inches your etape is. If you do that comment out your max inches too,
//i.e. if my etape is 12 inches comment out the 12 inch if statement also. In place of that follow the instructions 
//further down.
  if(EMPTY-(RATIO*InsertMaxInchesHere) >= RESISTANCE){ //Replace InsertMaxInches with your max inches.
    Inches = InsertMaxInchesHere; //Do it again here.
  }
  else if(EMPTY-(RATIO*11) >= Resistance){
    Inches = 11;
  }
  else if(EMPTY-(RATIO*10) >= Resistance){
    Inches = 10;
  }
  else if(EMPTY-(RATIO*9) >= Resistance){
  Inches = 9;
  }
  else if(EMPTY-(RATIO*8) >= Resistance){
  Inches = 8;
  }
  else if(EMPTY-(RATIO*7) >= Resistance){
  Inches = 7;
  }
  else if(EMPTY-(RATIO*6) >= Resistance){
  Inches = 6;
  }
  else if(EMPTY-(RATIO*5) >= Resistance){
  Inches = 5;
  }
  else if(EMPTY-(RATIO*4) >= Resistance){
  Inches = 4;
  }
  else if(EMPTY-(RATIO*3) >= Resistance){
  Inches = 3;
  }
  else if(EMPTY-(RATIO*2) >= Resistance){
  Inches = 2;
  }
  else if(EMPTY-RATIO >= Resistance){
  Inches = 1;
  }
  else(){
    Inches = 0;
  }
  
  return Inches;
  


//Print data to serial monitor. Add your code here if you want to add on to this.
void loop() {
  Resistance = ReadResistance(analog_pin, resistor_ohm, analog_ref);
  Serial.println(Resistance);
  Serial.println(FindInches(Ratio, Resistance, empty_resistance, full_resistance));
  delay(1000);
}
