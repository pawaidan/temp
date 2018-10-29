#include <stdio.h>
#include <wiringPi.h>
#include <curl/curl.h>

int curlUrl(char * URL) {
 CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
}
int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
pinMode (1, OUTPUT);
pinMode (2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
  printf("Waiting for event\n");
    digitalWrite (1, HIGH);
    curlUrl("https://maker.ifttt.com/trigger/alarm_triggered/with/key/cJK2hwgFfB4Wjisu4zbXK8");
    printf("Alarm\n");
    while(digitalRead(0) == 0);
    digitalWrite (1, LOW);
    
  }
  /*NOTREACHED*/
  return 0 ;
}
