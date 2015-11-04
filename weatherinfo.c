/**
 ******************************************************************************
 * @file       weatherinfo.c
 * @version    V0.0.1
 * @brief      API C source file of citydata.
 * @details    This file including all API functions's implement of weatherinfo.
 * @copy       Copyrigth(C), 2008-2012, LiuNing.
 * @date       2012-6-19
 *
 ******************************************************************************
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#ifdef __WIN32
#include <winsock.h>
#else
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#include "cjson.h"
#include "citydata.h"
#include "weatherinfo.h"
#include "ghttp.h"
#include "ghttp_constants.h"

#define HTTP_BUFF_SIZE      (4028u)  /**< 获取http时的报文缓存 */
typedef struct
{
    const char *pindex;
    unsigned int offset;
    unsigned int size;
} weather_item_t;

#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#define MOFFSET(structure, member)    ((unsigned int) &(((structure *)0)->member))
#define MEMBER_SIZE(structure, member)    (sizeof(((structure *)0)->member))

#define WEATHER1_ITEM(item, member) {item, \
    MOFFSET(weatherinfo1_t, member), MEMBER_SIZE(weatherinfo1_t, member)}
#define WEATHER2_ITEM(item, member) {item, \
    MOFFSET(weatherinfo2_t, member), MEMBER_SIZE(weatherinfo2_t, member)}
#define WEATHER3_ITEM(item, member) {item, \
    MOFFSET(weatherinfo3_t, member), MEMBER_SIZE(weatherinfo3_t, member)}

static const weather_item_t the_weather1_items[] =
{
    WEATHER1_ITEM("city", city),
    WEATHER1_ITEM("cityid", cityid),
    WEATHER1_ITEM("temp", temp),
    WEATHER1_ITEM("WD", WD),
    WEATHER1_ITEM("WS", WS),
    WEATHER1_ITEM("SD", SD),
    WEATHER1_ITEM("WSE", WSE),
    WEATHER1_ITEM("time", time),
    WEATHER1_ITEM("isRadar", isRadar),
    WEATHER1_ITEM("Radar", Radar),

};

static const weather_item_t the_weather2_items[] =
{
    WEATHER2_ITEM("city", city),
    WEATHER2_ITEM("cityid", cityid),
    WEATHER2_ITEM("temp1", temp1),
    WEATHER2_ITEM("temp2", temp2),
    WEATHER2_ITEM("weather", weather),
    WEATHER2_ITEM("city", city),
    WEATHER2_ITEM("img1", img1),
    WEATHER2_ITEM("ptime", ptime),

};

static const weather_item_t the_weather3_items[] =
{
    WEATHER3_ITEM("city", city),
    WEATHER3_ITEM("city_en", city_en),
    WEATHER3_ITEM("date_y", date_y),
    WEATHER3_ITEM("date", date),
    WEATHER3_ITEM("week", week),
    WEATHER3_ITEM("fchh", fchh),
    WEATHER3_ITEM("cityid", cityid),
    WEATHER3_ITEM("temp1", temp[0]),
    WEATHER3_ITEM("temp2", temp[1]),
    WEATHER3_ITEM("temp3", temp[2]),
    WEATHER3_ITEM("temp4", temp[3]),
    WEATHER3_ITEM("temp5", temp[4]),
    WEATHER3_ITEM("temp6", temp[5]),
    WEATHER3_ITEM("tempF1", tempF[0]),
    WEATHER3_ITEM("tempF2", tempF[1]),
    WEATHER3_ITEM("tempF3", tempF[2]),
    WEATHER3_ITEM("tempF4", tempF[3]),
    WEATHER3_ITEM("tempF5", tempF[4]),
    WEATHER3_ITEM("tempF6", tempF[5]),
    WEATHER3_ITEM("weather1", weather[0]),
    WEATHER3_ITEM("weather2", weather[1]),
    WEATHER3_ITEM("weather3", weather[2]),
    WEATHER3_ITEM("weather4", weather[3]),
    WEATHER3_ITEM("weather5", weather[4]),
    WEATHER3_ITEM("weather6", weather[5]),
    WEATHER3_ITEM("img1", img[0]),
    WEATHER3_ITEM("img2", img[1]),
    WEATHER3_ITEM("img3", img[2]),
    WEATHER3_ITEM("img4", img[3]),
    WEATHER3_ITEM("img5", img[4]),
    WEATHER3_ITEM("img6", img[5]),
    WEATHER3_ITEM("img_single", img_single),
    WEATHER3_ITEM("img_title1", img_title[0]),
    WEATHER3_ITEM("img_title2", img_title[1]),
    WEATHER3_ITEM("img_title3", img_title[2]),
    WEATHER3_ITEM("img_title4", img_title[3]),
    WEATHER3_ITEM("img_title5", img_title[4]),
    WEATHER3_ITEM("img_title6", img_title[5]),
    WEATHER3_ITEM("img_title_single", img_title_single),
    WEATHER3_ITEM("wind1", wind[0]),
    WEATHER3_ITEM("wind2", wind[1]),
    WEATHER3_ITEM("wind3", wind[2]),
    WEATHER3_ITEM("wind4", wind[3]),
    WEATHER3_ITEM("wind5", wind[4]),
    WEATHER3_ITEM("wind6", wind[5]),
    WEATHER3_ITEM("fx1", fx[0]),
    WEATHER3_ITEM("fx2", fx[1]),
    WEATHER3_ITEM("fl1", fl[0]),
    WEATHER3_ITEM("fl2", fl[1]),
    WEATHER3_ITEM("fl3", fl[2]),
    WEATHER3_ITEM("fl4", fl[3]),
    WEATHER3_ITEM("fl5", fl[4]),
    WEATHER3_ITEM("fl6", fl[5]),
    WEATHER3_ITEM("index", index),
    WEATHER3_ITEM("index_d", index_d),
    WEATHER3_ITEM("index48", index48),
    WEATHER3_ITEM("index48_d", index48_d),
    WEATHER3_ITEM("index_uv", index_uv),
    WEATHER3_ITEM("index48_uv", index48_uv),
    WEATHER3_ITEM("index_xc", index_xc),
    WEATHER3_ITEM("index_tr", index_tr),
    WEATHER3_ITEM("index_co", index_co),
    WEATHER3_ITEM("st1", st[0]),
    WEATHER3_ITEM("st2", st[1]),
    WEATHER3_ITEM("st3", st[2]),
    WEATHER3_ITEM("st4", st[3]),
    WEATHER3_ITEM("st5", st[4]),
    WEATHER3_ITEM("st6", st[5]),
    WEATHER3_ITEM("index_cl", index_cl),
    WEATHER3_ITEM("index_ls", index_ls),
    WEATHER3_ITEM("index_ag", index_ag),

};


#define PORTNUMBER     (80u)
#define WEB_WEATHER1   "http://www.weather.com.cn"
#define WEB_SND_MSG1   "/adat/sk/%09ld.html"
#define WEB_WEATHER2   "http://www.weather.com.cn"
#define WEB_SND_MSG2   "/adat/cityinfo/%09ld.html"
#define WEB_WEATHER3   "http://m.weather.com.cn"
#define WEB_SND_MSG3   "/mweather/%09ld.shtml"

//http://m.weather.com.cn/mweather/101020100.shtml
/**
 ******************************************************************************
 * @brief      获取城市天气信息weatherinfo (JSON格式)
 * @param[in]  *pcity_name  城市名
 * @param[in]  *pweather    天气信息保存地址
 * @param[in]  *pweather    天气信息保存地址
 *
 * @retval      0  成功获取天气信息
 * @retval     -1  传入参数有误
 * @retval     -2  在数据库中找不到城市名
 * @retval     -3  gethostbyname 出错
 * @retval     -4  socket        出错
 * @retval     -5  connect       出错
 * @retval     -6  找不到JSON数据
 *
 * @note

                                    * -天气获取地址01: http://www.weather.com.cn/data/sk/101210401.html
 * -天气获取地址01:  http://www.weather.com.cn/adat/sk/101110101.html
 * -天气获取地址02: http://www.weather.com.cn/data/cityinfo/101210401.html
 * -天气获取地址03: http://m.weather.com.cn/data/101210401.html
 ******************************************************************************
 */
int get_weather_from_socket(const char *pcity_name, char *pjson_weather, char type)
{
    char* uri;
    
    char web_weather[255];
    char web_snd_msg[255];  
  
    ghttp_request *request = NULL;
    ghttp_status status;
    FILE * pFile;
    char *buf;
    int size;
    char* pret = NULL;
    int bytes_read = 0;
    long int city_id = 0;
    /* 获取城市ID */
    if (0 != cd_get_city_id(pcity_name, &city_id))
    {
        fprintf(stderr, "get city id error\n");
        return -2;
    }

    switch(type)
    {
        case 0x01:
            sprintf(web_weather,WEB_WEATHER1);
            sprintf(web_snd_msg, WEB_SND_MSG1, city_id);
            strcat(web_weather,web_snd_msg); 
            break;
        case 0x02:
            sprintf(web_weather,WEB_WEATHER2);
            sprintf(web_snd_msg, WEB_SND_MSG2, city_id);
            strcat(web_weather,web_snd_msg); 
            break;
        case 0x03:
            sprintf(web_weather,WEB_WEATHER3);
            sprintf(web_snd_msg, WEB_SND_MSG3, city_id);
            strcat(web_weather,web_snd_msg); //获取URL
            break;
        default:
            return -1;
            break;
    }

    uri = web_weather;	
    
    printf("the url = %s \n",uri);
    printf("the city_id = %ld\n",city_id);

    pFile = fopen ( "get_weather_from_socket.html" , "wb" );
    request = ghttp_request_new();
    if(ghttp_set_uri(request, uri) == -1)
       return -1;
    
    if(ghttp_set_type(request, ghttp_type_get) == -1)//get
    	 return -1;
    ghttp_prepare(request);
    status = ghttp_process(request);
    if(status == ghttp_error)
    	 return -1;

    printf("Status code -> %d\n", ghttp_status_code(request));
    buf = ghttp_get_body(request);
 printf("the weather is %s \n",buf);
    bytes_read = ghttp_get_body_len(request);

    size = strlen(buf);//size == bytes_read
    fwrite (buf , 1 ,size , pFile );
    /* 寻找到第一个'{'拷贝至*pjson_weather中 */    

    pret = strchr((const char *)buf, '{');
    if (NULL == pret)
    {
        fprintf(stderr, "can not find weather info!\n");
        return -6;
    }
    memcpy((void *)pjson_weather, (const void *)pret, size);
    printf("bytes read %d \n",bytes_read);
    fclose(pFile);
    ghttp_request_destroy(request);
    return 0;
    
}

/**
 ******************************************************************************
 * @brief      获取城市天气信息weatherinfo
 * @param[in]  *pcity_name  城市名
 * @param[in]  *pweather    天气信息保存地址
 * @param[in]  *pweather    天气信息保存地址
 *
 * @retval      0  成功获取天气信息
 * @retval     -1  传入参数有误
 * @retval     -2  获取JSON数据出错
 *
 * @note
 * -天气获取地址01: http://www.weather.com.cn/data/sk/101210401.html
 * -天气获取地址02: http://www.weather.com.cn/data/cityinfo/101210401.html
 * -天气获取地址03: http://m.weather.com.cn/data/101210401.html
 ******************************************************************************
 */
int get_weatherinfo(const char *pcity_name, char *pweather, unsigned char type)
{
    int i;
    int ret;
    char json_weather[HTTP_BUFF_SIZE];
    int array_size = 0;
    const weather_item_t *pweather_items = NULL;
    cJSON *tmp = NULL;
    cJSON *root = NULL;
    cJSON *weatherinfo = NULL;

    if ((NULL == pcity_name) || (NULL == pweather))
    {
        fprintf(stderr, "%s argv error\n", __FUNCTION__);
        return -1;
    }

    switch(type)
    {
        case 0x01:
            pweather_items = the_weather1_items;
            array_size = ARRAY_SIZE(the_weather1_items);
            memset(pweather, 0x00, sizeof(weatherinfo1_t));
            break;
        case 0x02:
            pweather_items = the_weather2_items;
            array_size = ARRAY_SIZE(the_weather2_items);
            memset(pweather, 0x00, sizeof(weatherinfo2_t));
            break;
        case 0x03:
            pweather_items = the_weather3_items;
            array_size = ARRAY_SIZE(the_weather3_items);
            memset(pweather, 0x00, sizeof(weatherinfo3_t));
            break;
        default:
            return -1;
            break;
    }

    memset(json_weather, 0x00, sizeof(json_weather));
    ret = get_weather_from_socket(pcity_name, json_weather, type);
    if (0 != ret)
    {
        fprintf(stderr, "%s error, ret is %d\n", __FUNCTION__, ret);
        return -2;
    }

    root = cJSON_Parse((const char *)&json_weather);
    weatherinfo = cJSON_GetObjectItem(root, "weatherinfo");

    for (i = 0; i < array_size; i++)
    {
        tmp = cJSON_GetObjectItem(weatherinfo, pweather_items[i].pindex);

        if (NULL == tmp)
        {
            continue;
        }

        if (cJSON_String == tmp->type)
        {
            //printf("%s: %s\n", pweather_items[i].pindex, tmp->valuestring);
            memcpy((void *)(pweather + pweather_items[i].offset), (const void *)(tmp->valuestring), \
                ((strlen(tmp->valuestring) + 1) < pweather_items[i].size)
                ? (strlen(tmp->valuestring) + 1) : pweather_items[i].size);
            //printf("offset: %d\n", pweather_items[i].offset);
            //printf("size  : %d\n", pweather_items[i].size);
            //printf("str   : %s\n", (pweather + pweather_items->offset));
        }
    }

    cJSON_Delete(root);

    return 0;
}

