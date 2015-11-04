/**
 ******************************************************************************
 * @file       weather_main.c
 * @version    V0.0.1
 * @brief      获取天气预报测试程序
 * @details    This file including all API functions's implement of weather_main.
 * @copy       Copyrigth(C), 2008-2012, LiuNing.
 * @date       2012-6-19
 *
 ******************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "weatherinfo.h"
#include "music_driver_by_weather.h"
#define LOG_NAME   "./weather_info.txt"

int main(int argc, char **argv)
{
	FILE *fd = NULL;
    weatherinfo1_t weatherinfo1;
    weatherinfo2_t weatherinfo2;
    weatherinfo3_t weatherinfo3;

    if (0 != get_weatherinfo("湘潭", (char *)&weatherinfo1, 0x01))
    {
        printf("get_weatherinfo err, type is:%d\n", 0x01);
        return -1;
    }
/*
    if (get_weatherinfo("金华", (char *)&weatherinfo2, 0x02))
    {
        printf("get_weatherinfo err, type is:%d\n", 0x01);
        return -1;
    }
    if (get_weatherinfo("杭州", (char *)&weatherinfo3, 0x03))
    {
        printf("get_weatherinfo err, type is:%d\n", 0x01);
        return -1;
    }
*/
 //   music_driver_by_weather(weatherinfo2.weather);	
//printf("excuted sucessful");
/*	fd = fopen(LOG_NAME, "wb");
	if (fd == NULL)
	{
		printf("log_file open err\n");
	}
    fprintf(fd, "============================================\n");
    fprintf(fd, "********   Get Weather Info OK!     ********\n");
    fprintf(fd, "============================================\n");
    fprintf(fd, "some of Info1:\n");
    fprintf(fd, "    city    : %s\n", weatherinfo1.city);
    fprintf(fd, "    cityid  : %s\n", weatherinfo1.cityid);
    fprintf(fd, "    temp    : %s\n", weatherinfo1.temp);

    fprintf(fd, "\nsome of Info2:\n");
    fprintf(fd, "    city    : %s\n", weatherinfo2.city);
    fprintf(fd, "    cityid  : %s\n", weatherinfo2.cityid);
    fprintf(fd, "    weather : %s\n", weatherinfo2.weather);
    fprintf(fd, "\nsome of Info3:\n");
    fprintf(fd, "    city    : %s\n", weatherinfo3.city);
    fprintf(fd, "    cityid  : %s\n", weatherinfo3.cityid);
    fprintf(fd, "    weather : %s\n", weatherinfo3.weather[0]);
    fprintf(fd, "============================================\n");

    fclose(fd);
	*/
    return 0;
}

