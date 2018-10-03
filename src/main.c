#include <stdio.h>
#include <stdlib.h>
#include "sensor.c"
#include "http.c"

int running = 1;

int min(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<=arraylen; i++) {
		if (array[i] < result) {
			result = array[i];
		}
	}
	return result;
}

int max(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<=arraylen; i++) {
		if (array[i] > result) {
			result = array[i];
		}
	}
	return result;
}

int avg(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<=arraylen; i++) {
		result += array[i];
	}
	return result / arraylen;
}

void loop() {
	int minute[60];
	int i;
	
	while (running) {
		//printf("RPM: %d\n", counter);
		//counter = 0;
		
		for(i=0; i<=60; i++) {
			minute[i] = counter;
			counter = 0;
			delay(1000);
			//sendToServer(0, 0, 0);
		}
	}
}

int main(int argc, char **args) {
	initSensor();
	initHttp();
	loop();
	return 0;
}
