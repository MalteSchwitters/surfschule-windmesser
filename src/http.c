#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

#define APIKEY "iGnhjEGpo34IrbWNfJWAXCtzCYemR7lwRnLTJseSeBaFyfvzGYs4XHTG3xli8CZnngu7tUqOYLApHS3dBmV1LTS79vBMwxhRXX3825DNIdPgAPdNbsLZXxxcfQmDF0oK"
#define POSTURL "https://api.grosses-meer.surf/api/weather/windspeed"

CURL *curl;

void cleanup() {
    curl_easy_cleanup(curl);
}

int sendToServer(int sum, int min, int max, int avg) {
    char request[400];
    snprintf(request, 400, "auth=%s&rpm=%i&min=%i&max=%i&avg=%i", APIKEY, sum, min, max, avg);
    //printf("Request: %s\n", request);

    CURLcode res;
    if (curl) {
        //curl_easy_setopt(curl, CURLOPT_PUT, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, POSTURL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
    return 1;
}

int initHttp() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    return 0;
}
