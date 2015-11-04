#include <stdio.h>
#include <string.h>
int music_driver_by_weather(char* weather)
{
    char* tmp = weather;
    char str_weather[255];
    memset(str_weather,0,255);
/*    str_weather[0] = '晴';
    str_weather[2] = '阴';
    str_weather[4] = '云';
    str_weather[6] = '雨';
    str_weather[8] = '雷';
  */  printf("str_weather = %s\n",str_weather);
    printf("excuted sucessful\n");
    return 0;
}
