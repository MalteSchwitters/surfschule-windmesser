#include <stdio.h>
#include <stdlib.h>
#include "sensor.c"
#include "http.c"


int running = 1;



int readSensor() {
	while(1) {
		waitForInterrupt(SENSOR_PIN, -1) ;
		int value = digitalRead(0);
		printf("Sensor value: %i\n", value);
	}
	return 0;
}

int main(int argc, char **args) {
	initSensor();
	initHttp();
	
	while (running) {
		//printf("RPM: %d\n", counter);
		//counter = 0;
		delay(60 * 1000);
		//sendToServer();
	}
	return 0;
}
