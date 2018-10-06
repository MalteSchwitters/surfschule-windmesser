#include <stdio.h>
#include <stdlib.h>
#include "sensor.c"
#include "http.c"

int running = 1;

int calcMin(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<arraylen; i++) {
		if (array[i] < result) {
			result = array[i];
		}
	}
	return result;
}

int calcMax(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<arraylen; i++) {
		if (array[i] > result) {
			result = array[i];
		}
	}
	return result;
}

int calcSum(int *array, int arraylen) {
	int result;
	int i;
	for (i=0; i<arraylen; i++) {
		result += array[i];
	}
	return result;
}

void loop() {	
	int minute[60];
	int i;
	
	while (running) {
		for(i=0; i<60; i++) {
			delay(1000);
			minute[i] = rpm;
			rpm = 0;
			printf("-");
			fflush(stdout);
			//printf("%i rps\n", minute[i]);
		}
		//for (i=0; i<60
		printf("\n");
		double sum = calcSum(minute, 60);
		double min = calcMin(minute, 60);
		double max = calcMax(minute, 60);
		double avg = sum / 60;
		printf("RPM: %f\n", sum);
		printf("MIN: %f\n", min);
		printf("MAX: %f\n", max);
		printf("AVG: %f\n", avg);
		sendToServer(sum);
	}
}

int main(int argc, char **args) {
	initSensor();
	initHttp();
	loop();
	return 0;
}
