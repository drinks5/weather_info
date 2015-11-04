/**
 ******************************************************************************
 * @file       weatherinfo.h
 * @version    V0.0.1
 * @brief      API C source file of citydata.
 * @details    This file including all API functions's implement of weatherinfo.
 * @copy       Copyrigth(C), 2008-2012, LiuNing.
 * @date       2012-6-19
 *
 ******************************************************************************
 */

#ifndef __WEATHERINFO_H__
#define __WEATHERINFO_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * 地址:http://www.weather.com.cn/data/sk/101210401.html
 * {"weatherinfo":{
 *     "city":"宁波",
 *     "cityid":"101210401",
 *     "temp":"23",
 *     "WD":"南风",
 *     "WS":"1级",
 *     "SD":"93%",
 *     "WSE":"1",
 *     "time":"09:00",
 *     "isRadar":"1",
 *     "Radar":"JC_RADAR_AZ9574_JB"}}
 */
typedef struct
{
    char city[20];    /**< 城市名     */
    char cityid[10];  /**< 城市ID     */
    char temp[4];     /**< 温度       */
    char WD[12];      /**< 风向       */
    char WS[8];       /**< 风速       */
    char SD[4];       /**< 湿度       */
    char WSE[4];      /**< 风力       */
    char time[8];     /**< 发布时间   */
    char isRadar[4];  /**< 是否有雷达 */
    char Radar[20];   /**< 雷达图地址 */
    
} weatherinfo1_t;

/**
 * 地址:http://www.weather.com.cn/data/cityinfo/101210401.html
 * {"weatherinfo":{
 *     "city":"宁波",
 *     "cityid":"101210401",
 *     "temp1":"27℃",
 *     "temp2":"22℃",
 *     "weather":"大到暴雨转阵雨",
 *     "img1":"d23.gif",
 *     "img2":"n3.gif",
 *     "ptime":"08:00"}}
 */
typedef struct
{
    char city[20];    /**< 城市名   */
    char cityid[10];  /**< 城市ID   */
    char temp1[8];    /**< 温度h    */
    char temp2[8];    /**< 温度l    */
    char weather[20]; /**< 天气     */
    char img1[12];    /**< 日图     */
    char img2[12];    /**< 夜图     */
    char ptime[8];    /**< 发布时间 */
    
} weatherinfo2_t;

/**
 * 地址:http://m.weather.com.cn/data/101210401.html
 * {"weatherinfo":{
 *
 *     //基本信息
 *     "city":"宁波","city_en":"ningbo",
 *     "date_y":"2012年6月17日","date":"","week":"星期日","fchh":"11","cityid":"101210401",
 *
 *     //摄氏温度
 *     "temp1":"25℃~23℃","temp2":"27℃~22℃","temp3":"27℃~23℃",
 *     "temp4":"28℃~22℃","temp5":"30℃~23℃","temp6":"29℃~22℃",
 *
 *     //华氏温度
 *     "tempF1":"77℉~73.4℉","tempF2":"80.6℉~71.6℉","tempF3":"80.6℉~73.4℉",
 *     "tempF4":"82.4℉~71.6℉","tempF5":"86℉~73.4℉","tempF6":"84.2℉~71.6℉",
 *
 *     //天气描述
 *     "weather1":"中到大雨转大雨","weather2":"阵雨","weather3":"阵雨",
 *     "weather4":"小雨转阴","weather5":"阵雨","weather6":"阵雨",
 *
 *     //天气描述图片序列号
 *     "img1":"22","img2":"9","img3":"3","img4":"99","img5":"3","img6":"99",
 *     "img7":"7","img8":"2","img9":"3","img10":"99","img11":"3","img12":"99",
 *     "img_single":"22",
 *
 *     //图片名称
 *     "img_title1":"中到大雨","img_title2":"大雨","img_title3":"阵雨","img_title4":"阵雨",
 *     "img_title5":"阵雨","img_title6":"阵雨","img_title7":"小雨","img_title8":"阴",
 *     "img_title9":"阵雨","img_title10":"阵雨","img_title11":"阵雨","img_title12":"阵雨",
 *     "img_title_single":"中到大雨",
 *
 *     //风速描述
 *     "wind1":"微风","wind2":"微风","wind3":"微风",
 *     "wind4":"微风","wind5":"微风","wind6":"微风",
 *     "fx1":"微风","fx2":"微风",
 *     "fl1":"小于3级","fl2":"小于3级","fl3":"小于3级",
 *     "fl4":"小于3级","fl5":"小于3级","fl6":"小于3级",
 *
 *     //今日穿衣指数
 *     "index":"暖",
 *     "index_d":"较凉爽，建议着长袖衬衫加单裤等春秋过渡装。年老体弱者宜着针织长袖衬衫、马甲和长裤。",
 *
 *     //48小时穿衣指数
 *     "index48":"热",
 *     "index48_d":"天气较热，建议着短裙、短裤、短套装、T恤等夏季服装。年老体弱者宜着长袖衬衫和单裤。",
 *
 *     //紫外线及48小时紫外线
 *     "index_uv":"最弱","index48_uv":"弱",
 *
 *     //洗车
 *     "index_xc":"不宜",
 *
 *     //旅游
 *     "index_tr":"较不宜",
 *
 *     //舒适指数
 *     "index_co":"较舒适",
 *
 *     //
 *     "st1":"23","st2":"21","st3":"25","st4":"20","st5":"25","st6":"21",
 *
 *     //晨练
 *     "index_cl":"不宜",
 *
 *     //晾晒
 *     "index_ls":"不宜",
 *
 *     //过敏
 *     "index_ag":"极不易发"}}
 */
typedef struct
{
    char city[20];              /**< 城市名           */
    char city_en[20];           /**< 城市名en         */
    char date_y[16];            /**< 时间             */
    char date[16];              /**<                  */
    char week[8];               /**< 星期             */
    char fchh[4];               /**<                  */
    char cityid[10];            /**< 城市ID           */
    char temp[6][16];           /**< 摄氏温度         */
    char tempF[6][16];          /**< 华氏温度         */
    char weather[6][20];        /**< 天气描述         */
    char img[12][4];            /**< 天气描述图片序号 */
    char img_single[4];         /**< 天气描述图片序号 */
    char img_title[20];         /**< 图片名称         */
    char img_title_single[20];  /**< 图片名称         */
    char wind[6][12];           /**< 风速描述         */
    char fx[2][12];             /**< 风速描述         */
    char fl[6][12];             /**< 风力描述         */
    char index[8];              /**< 今日穿衣指数     */
    char index_d[100];          /**< 今日穿衣指数     */
    char index48[8];            /**< 48小时穿衣指数   */
    char index48_d[100];        /**< 48小时穿衣指数   */
    char index_uv[8];           /**< 今日紫外线指数   */
    char index48_uv[8];         /**< 48小时紫外线指数 */
    char index_xc[12];          /**< 洗车指数         */
    char index_tr[12];          /**< 旅游指数         */
    char index_co[12];          /**< 舒适指数         */
    char st[6][4];              /**< ??               */
    char index_cl[12];          /**< 晨练指数         */
    char index_ls[12];          /**< 晾晒指数         */
    char index_ag[12];          /**< 极不易发         */
    
} weatherinfo3_t;

extern int get_weather_from_socket(const char *pcity_name, char *pjson_weather, char type);
extern int get_weatherinfo(const char *pcity_name, char *pweather, unsigned char type);

#ifdef __cplusplus
}
#endif

#endif /* __WEATHERINFO_H__ */

