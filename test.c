#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "analyze_Weather.h"

int main()
{
    char* data = "晴转多云";
    return Analyze_Weather(data);    
}
/*    char* weather = "啊天气雨";
    char tmp = '啊';
       printf("%c\n",tmp);
    char* flag;
    if(strchr(weather,tmp) == NULL)
       {printf("weather error");
       return -1;}
    printf("weather right\n");
    printf("%c\n",tmp);

*/

