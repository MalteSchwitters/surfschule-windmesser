#include <stdio.h>
#include <curl/curl.h>
#include <wiringPi.h>

CURL *curl;

void init() {
	wiringPiSetup () ;
	//pinMode (0, INTPUT) ;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
}

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
		waitForInterrupt (0, -1) ;
		int value = digitalRead(0);
		printf("Sensor value: %i\n", value);
	}
	return 0;
}

int main(int argc, char **args) {
	init();
	readSensor();
	sendToServer();
}
