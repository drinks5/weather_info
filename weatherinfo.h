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
 * ��ַ:http://www.weather.com.cn/data/sk/101210401.html
 * {"weatherinfo":{
 *     "city":"����",
 *     "cityid":"101210401",
 *     "temp":"23",
 *     "WD":"�Ϸ�",
 *     "WS":"1��",
 *     "SD":"93%",
 *     "WSE":"1",
 *     "time":"09:00",
 *     "isRadar":"1",
 *     "Radar":"JC_RADAR_AZ9574_JB"}}
 */
typedef struct
{
    char city[20];    /**< ������     */
    char cityid[10];  /**< ����ID     */
    char temp[4];     /**< �¶�       */
    char WD[12];      /**< ����       */
    char WS[8];       /**< ����       */
    char SD[4];       /**< ʪ��       */
    char WSE[4];      /**< ����       */
    char time[8];     /**< ����ʱ��   */
    char isRadar[4];  /**< �Ƿ����״� */
    char Radar[20];   /**< �״�ͼ��ַ */
    
} weatherinfo1_t;

/**
 * ��ַ:http://www.weather.com.cn/data/cityinfo/101210401.html
 * {"weatherinfo":{
 *     "city":"����",
 *     "cityid":"101210401",
 *     "temp1":"27��",
 *     "temp2":"22��",
 *     "weather":"�󵽱���ת����",
 *     "img1":"d23.gif",
 *     "img2":"n3.gif",
 *     "ptime":"08:00"}}
 */
typedef struct
{
    char city[20];    /**< ������   */
    char cityid[10];  /**< ����ID   */
    char temp1[8];    /**< �¶�h    */
    char temp2[8];    /**< �¶�l    */
    char weather[20]; /**< ����     */
    char img1[12];    /**< ��ͼ     */
    char img2[12];    /**< ҹͼ     */
    char ptime[8];    /**< ����ʱ�� */
    
} weatherinfo2_t;

/**
 * ��ַ:http://m.weather.com.cn/data/101210401.html
 * {"weatherinfo":{
 *
 *     //������Ϣ
 *     "city":"����","city_en":"ningbo",
 *     "date_y":"2012��6��17��","date":"","week":"������","fchh":"11","cityid":"101210401",
 *
 *     //�����¶�
 *     "temp1":"25��~23��","temp2":"27��~22��","temp3":"27��~23��",
 *     "temp4":"28��~22��","temp5":"30��~23��","temp6":"29��~22��",
 *
 *     //�����¶�
 *     "tempF1":"77�H~73.4�H","tempF2":"80.6�H~71.6�H","tempF3":"80.6�H~73.4�H",
 *     "tempF4":"82.4�H~71.6�H","tempF5":"86�H~73.4�H","tempF6":"84.2�H~71.6�H",
 *
 *     //��������
 *     "weather1":"�е�����ת����","weather2":"����","weather3":"����",
 *     "weather4":"С��ת��","weather5":"����","weather6":"����",
 *
 *     //��������ͼƬ���к�
 *     "img1":"22","img2":"9","img3":"3","img4":"99","img5":"3","img6":"99",
 *     "img7":"7","img8":"2","img9":"3","img10":"99","img11":"3","img12":"99",
 *     "img_single":"22",
 *
 *     //ͼƬ����
 *     "img_title1":"�е�����","img_title2":"����","img_title3":"����","img_title4":"����",
 *     "img_title5":"����","img_title6":"����","img_title7":"С��","img_title8":"��",
 *     "img_title9":"����","img_title10":"����","img_title11":"����","img_title12":"����",
 *     "img_title_single":"�е�����",
 *
 *     //��������
 *     "wind1":"΢��","wind2":"΢��","wind3":"΢��",
 *     "wind4":"΢��","wind5":"΢��","wind6":"΢��",
 *     "fx1":"΢��","fx2":"΢��",
 *     "fl1":"С��3��","fl2":"С��3��","fl3":"С��3��",
 *     "fl4":"С��3��","fl5":"С��3��","fl6":"С��3��",
 *
 *     //���մ���ָ��
 *     "index":"ů",
 *     "index_d":"����ˬ�������ų�������ӵ���ȴ������װ������������������֯�����������׺ͳ��㡣",
 *
 *     //48Сʱ����ָ��
 *     "index48":"��",
 *     "index48_d":"�������ȣ������Ŷ�ȹ���̿㡢����װ��T�����ļ���װ���������������ų�������͵��㡣",
 *
 *     //�����߼�48Сʱ������
 *     "index_uv":"����","index48_uv":"��",
 *
 *     //ϴ��
 *     "index_xc":"����",
 *
 *     //����
 *     "index_tr":"�ϲ���",
 *
 *     //����ָ��
 *     "index_co":"������",
 *
 *     //
 *     "st1":"23","st2":"21","st3":"25","st4":"20","st5":"25","st6":"21",
 *
 *     //����
 *     "index_cl":"����",
 *
 *     //��ɹ
 *     "index_ls":"����",
 *
 *     //����
 *     "index_ag":"�����׷�"}}
 */
typedef struct
{
    char city[20];              /**< ������           */
    char city_en[20];           /**< ������en         */
    char date_y[16];            /**< ʱ��             */
    char date[16];              /**<                  */
    char week[8];               /**< ����             */
    char fchh[4];               /**<                  */
    char cityid[10];            /**< ����ID           */
    char temp[6][16];           /**< �����¶�         */
    char tempF[6][16];          /**< �����¶�         */
    char weather[6][20];        /**< ��������         */
    char img[12][4];            /**< ��������ͼƬ��� */
    char img_single[4];         /**< ��������ͼƬ��� */
    char img_title[20];         /**< ͼƬ����         */
    char img_title_single[20];  /**< ͼƬ����         */
    char wind[6][12];           /**< ��������         */
    char fx[2][12];             /**< ��������         */
    char fl[6][12];             /**< ��������         */
    char index[8];              /**< ���մ���ָ��     */
    char index_d[100];          /**< ���մ���ָ��     */
    char index48[8];            /**< 48Сʱ����ָ��   */
    char index48_d[100];        /**< 48Сʱ����ָ��   */
    char index_uv[8];           /**< ����������ָ��   */
    char index48_uv[8];         /**< 48Сʱ������ָ�� */
    char index_xc[12];          /**< ϴ��ָ��         */
    char index_tr[12];          /**< ����ָ��         */
    char index_co[12];          /**< ����ָ��         */
    char st[6][4];              /**< ??               */
    char index_cl[12];          /**< ����ָ��         */
    char index_ls[12];          /**< ��ɹָ��         */
    char index_ag[12];          /**< �����׷�         */
    
} weatherinfo3_t;

extern int get_weather_from_socket(const char *pcity_name, char *pjson_weather, char type);
extern int get_weatherinfo(const char *pcity_name, char *pweather, unsigned char type);

#ifdef __cplusplus
}
#endif

#endif /* __WEATHERINFO_H__ */

