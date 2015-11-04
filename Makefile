#This is the Makefile for Weatherinfo by LiuNing
APP_NAME = weather_get

OBJS    += citydata.o     \
           cjson.o        \
		   weatherinfo.o  \
		   weather_main.o \
		   music_driver_by_weather.o
CROSS_COMPILE =
#CROSS_COMPILE = arm-linux-

CCFLAGS   = -Wall -Os -lghttp
LDFLAGS   = -lm
ifdef WIN32
LDFLAGS  += -lwsock32
endif
OBJDIR    = ./obj/

CC        =  $(CROSS_COMPILE)gcc
AS        =  $(CROSS_COMPILE)as
LD        =  $(CROSS_COMPILE)ld
OBJDUMP   =  $(CROSS_COMPILE)objdump
OBJCOPY   =  $(CROSS_COMPILE)objcopy
STRIP     =  $(CROSS_COMPILE)strip

all:$(APP_NAME)

$(APP_NAME): $(OBJS)
	$(CC) -g $(OBJS) -o $(APP_NAME) $(CCFLAGS) $(LDFLAGS)
ifdef WIN32	
	$(STRIP) $(APP_NAME).exe
else
	$(STRIP) $(APP_NAME)
endif

citydata.o:
	$(CC) -g -c $(CCFLAGS) citydata.c
	
cjson.o:
	$(CC) -g -c $(CCFLAGS) cjson.c
	
weatherinfo.o:
	$(CC) -g -c $(CCFLAGS) weatherinfo.c
	
weather_main.o:
	$(CC) -g -c $(CCFLAGS) weather_main.c
music_driver_by_music.o:
	$(CC) -g -c $(CCFLAGS) music_driver_by_music.c
clean:
ifdef WIN32	
	rm -f $(APP_NAME).exe *.o
else
	rm -f $(APP_NAME) *.o *.txt *.html
endif

re: clean all
