/**
 ******************************************************************************
 * @file       citydata.h
 * @version    V0.0.1
 * @brief      API C source file of citydata.
 * @details    This file including all API functions's implement of citydata.
 * @copy       Copyrigth(C), 2008-2012, LiuNing.
 * @date       2012-6-19
 *
 ******************************************************************************
 */
#ifndef __CITYDATA_H__
#define __CITYDATA_H__

#ifdef __cplusplus
extern "C"
{
#endif

extern int cd_get_city_id(const char *pcity_name, long int *pcity_id);
extern int cd_get_city_name(long int city_id, char *pcity_name);

#ifdef __cplusplus
}
#endif

#endif /* __CITYDATA_H__ */
