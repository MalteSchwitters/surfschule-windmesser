#include <stdio.h>
#include <stdlib.h>
#include "sensor.c"
#include "http.c"

int running = 1;

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
