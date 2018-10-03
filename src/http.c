#include <stdio.h>
#include <curl/curl.h>

CURL *curl;
char apikey[] = "**********";
char baseurl[14] = "https://api.grosses-meer.surf/api/";

void cleanup() {
    curl_easy_cleanup(curl);
}

int sendToServer(int min, int avg, int max) {
    // textA = textA + textB
    // strcat(textA, textB);
    
    CURLcode res;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.grosses-meer.surf/api/status");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
}

int initHttp() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    return 0;
}
