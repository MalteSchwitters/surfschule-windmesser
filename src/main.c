#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <curl/curl.h>
#include <wiringPi.h>

#define SENSOR_PIN 0

CURL *curl;
volatile int counter = 0;


void cleanup() {
	curl_easy_cleanup(curl);
}

void sendToServer() {
	CURLcode res;
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.grosses-meer.surf/api/status");
		res = curl_easy_perform(curl);
	        if(res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
	}
}

int readSensor() {
	while(1) {
		waitForInterrupt(SENSOR_PIN, -1) ;
		int value = digitalRead(0);
		printf("Sensor value: %i\n", value);
	}
	return 0;
}

void sensorInterrupt(void) {
	counter++;
}

int init() {
	wiringPiSetup () ;
	//pinMode (0, INTPUT) ;
	if (wiringPiISR(SENSOR_PIN, INT_EDGE_FALLING, &sensorInterrupt) < 0 ) {
		fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno));
		return 1;
	}
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
}

int main(int argc, char **args) {
	init();
	while (1) {
		printf("RPM: %d\n", counter);
		counter = 0;
		delay(60 * 1000);
	}
	sendToServer();
	return 0;
}
