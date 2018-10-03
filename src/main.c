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

int sum(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<=arraylen; i++) {
		result += array[i];
	}
	return result;
}

int avg(int *array, int arraylen) {
	return sum(array, arraylen) / arraylen;
}

void loop() {
	int minute[60];
	int i;
	
	while (running) {
		for(i=0; i<=60; i++) {
			minute[i] = counter;
			counter = 0;
			printf("-");
			fflush(stdout);
			delay(1000);
		}
		printf("\n");
		printf("RPM: %i\n", sum(minute, 60));
		printf("AVG: %i\n", avg(minute, 60));
		printf("MIN: %i\n", min(minute, 60));
		printf("MAX: %i\n", max(minute, 60));
		//sendToServer(0, 0, 0);
	}
}

int main(int argc, char **args) {
	initSensor();
	initHttp();
	loop();
	return 0;
}
