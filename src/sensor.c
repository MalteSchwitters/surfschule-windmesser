#include <errno.h>
#include <wiringPi.h>

#define SENSOR_PIN 0

volatile int counter = 0;

int initSensor() {
	if (wiringPiSetup() < 0) {
		fprintf (stderr, "Unable to setup wiringPi: %s\n", strerror(errno));
		return 1;
	}
	pinMode(SENSOR_PIN, INPUT);
	if (wiringPiISR(SENSOR_PIN, INT_EDGE_RISING, &sensorInterrupt) < 0 ) {
		fprintf (stderr, "Unable to setup ISR: %s\n", strerror(errno));
		return 1;
	}
	return 0;
}

void sensorInterrupt(void) {
	counter++;
	printf("Interrupt #%i!\n", counter);
}

int readSensor() {
	while(1) {
		waitForInterrupt(SENSOR_PIN, -1) ;
		int value = digitalRead(0);
		printf("Sensor value: %i\n", value);
	}
	return 0;
}
