/*#include<graphics.h>
#include<string>
#include<iostream>
#include<time.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
IMAGE spaceman[59];
IMAGE point[3];
SYSTEM_POWER_STATUS sysPowerStatus;
void setTextStyle(int height, int weight, const char* type) {
	LOGFONT f = { 0 };
	f.lfHeight = height;
	f.lfWeight = weight;
	strcpy_s(f.lfFaceName, type);
	settextstyle(&f);
}
void loadImg() {
	char fileName[50] = { 0 };
	for (int i = 0; i < 59; i++) {
		sprintf_s(fileName, "./images/human (%d).jpg", i + 2);
		loadimage(spaceman + i, fileName, 140, 130);
	}	
	for (int i = 0; i < 3; i++) {
		sprintf_s(fileName, "./images/point%d.png", i);
		loadimage(point + i, fileName, 60, 22);
	}
}
void putImg() {//sleep()函数不释放锁 所以不能用
	static int i = 0,j = 0,t1 = 0,t2 = 0;//只初始化一次 到程序结束时才释放空间
	int t3 = clock(),t4 = clock();
	if (t3 - t1 > 15) {
		putimage(180, 225,spaceman + i);
		t1 = t3;
		i = (i + 1) % 59;	
	}
	if (t4 - t2 > 700) {
		putimage(243, 430, point + j);
		t2 = t4;
		j = (j + 1) % 3;
	}
}
void timeShow() {
	time_t currentTime = time(NULL);
	struct tm* now = new struct tm;
	localtime_s(now, &currentTime);
	char buf[40] = { 0 };
	settextcolor(BLACK);
	sprintf_s(buf, "%02d : %02d",now->tm_hour, now->tm_min);
	setTextStyle(75, 65, "Arial");
	outtextxy(110,150,buf);
	sprintf_s(buf, ":%02d", now->tm_sec);
	setTextStyle(40, 30, "Arial");
	outtextxy(330, 180, buf);
	sprintf_s(buf, "%d . %d.",now->tm_mon+1, now->tm_mday);
	setTextStyle(30, 20, "Arial");
	outtextxy(330, 280, buf);
	setTextStyle(25, 20, "Arial");
	switch (now->tm_wday) {
	case 0: {char temp[40] = "Sunday"; outtextxy(325, 320, temp); break; }
	case 1: {char temp[40] = "Monday"; outtextxy(325, 320, temp); break; }
	case 2: {char temp[40] = "Tuesday"; outtextxy(325, 320, temp); break; }
	case 3: {char temp[40] = "Wednesday"; outtextxy(325, 320, temp); break; }
	case 4: {char temp[40] = "Thursday"; outtextxy(325, 320, temp); break; }
	case 5: {char temp[40] = "Friday"; outtextxy(325, 320, temp); break; }
	case 6: {char temp[40] = "Saturday"; outtextxy(325, 320, temp); }
	}
}
void batteryShow() {
	char buf[40] = { 0 };
	GetSystemPowerStatus(&sysPowerStatus);
	sprintf_s(buf, "电量： %02d %%",int(sysPowerStatus.BatteryLifePercent));
	setTextStyle(25, 15, "Arial");
	outtextxy(180, 390, buf);
	if ((int)sysPowerStatus.ACLineStatus == 1) {//这里需要改成==
		setTextStyle(20, 10, "Arial");
		outtextxy(190, 430, "充电中");
	}
	
}
void setScreen() {
	initgraph(500, 500, 0);
	setbkcolor(RGB(223, 230, 240));
	cleardevice();
	setlinecolor(RGB(68,68,68));
	setlinestyle(PS_SOLID, 15);
	setfillcolor(RGB(223, 230, 240));
	fillellipse(20, 20, 480, 480);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 10);
	line(210, 30, 210, 125);
	line(55, 125, 445, 125);
	line(55, 375, 445, 375);
}
int main() {
	
	setScreen();
	loadImg();
	while (true) {
		putImg();
		timeShow();
		batteryShow();
	}
	getchar();
	return 0;
}*/