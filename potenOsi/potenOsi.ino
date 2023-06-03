#define TPIN 5
#define MSEC 1000
#define NSECP 10

void setup() {
	Serial.begin(9600);
	DDRC = 0b00000000;
	DDRD = 0b00100000;
}

void loop() {
	unsigned long currentTime = micros();
	unsigned int diff = 0;
	int dval = analogRead(TPIN);
	int percent = ((float)dval / 1024) * 100;
	int psec = NSECP * percent;
	do {
		digitalWrite(5, diff < psec? HIGH : LOW);
		diff = micros() - currentTime;
	} while(diff <= 1000);
}

