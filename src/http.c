#include <stdio.h>
#include <curl/curl.h>

CURL *curl;
char **apikey = "**********";
char **baseurl = "https://api.grosses-meer.surf/api/"

int initHttp() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    return 0;
}

void cleanup() {
    curl_easy_cleanup(curl);
}

int sendToServer(int min, int avg, int max) {
    CURLcode res;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.grosses-meer.surf/api/status");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
}
