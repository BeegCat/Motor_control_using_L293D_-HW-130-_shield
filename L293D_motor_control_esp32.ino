
constexpr uint8_t SerialPin = 21;
constexpr uint8_t ClockPin = 19;
constexpr uint8_t LatchPin = 23;
constexpr uint8_t EnablePin = 18;

constexpr uint8_t MotorLeft = 0b00000100;
constexpr uint8_t MotorRight = 0b00001000;
constexpr uint8_t MotorOff = 0b00000000;

void pulse(uint8_t pin){
	digitalWrite(pin, HIGH);
	delay(1);
	digitalWrite(pin, LOW);
	delay(1);
}


void writeMotor(uint8_t control){
  for(uint8_t i = 0; i < 8; ++i){
    digitalWrite(SerialPin, control & 0x80 ? HIGH : LOW);
    pulse(ClockPin);
    control <<= 1;
  }
  pulse(LatchPin);  
}

void setup(){
  Serial.begin(115200);
  pinMode(SerialPin, OUTPUT);
  pinMode(ClockPin, OUTPUT);
  pinMode(LatchPin, OUTPUT);
  pinMode(EnablePin, OUTPUT);

  digitalWrite(EnablePin, LOW);
}


void loop(){

  writeMotor(MotorLeft);
  Serial.println("rotating CCW");
  delay(2000);

  writeMotor(MotorOff);
  Serial.println("motor off");
  delay(1000);

  writeMotor(MotorRight);
  Serial.println("rotating CW");
  delay(2000);

  writeMotor(MotorOff);
  Serial.println("motor off");
  delay(1000);
}