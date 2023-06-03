#define TPIN 2
const float analogRes = (float)5000 / 1023;

void setup() {
	Serial.begin(9600);
	DDRC = 0b00000000;
	DDRD = 0b00000100;
	Serial.println("#	mV	°");
}

void loop() {
	int decVolt = analogRead(TPIN);
	float volt = decVolt * analogRes;
	Serial.print(decVolt);
	Serial.print("\t");
	Serial.print(volt);
	Serial.print("\t");
	Serial.println(volt / 10);
}

