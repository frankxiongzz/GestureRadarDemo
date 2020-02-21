// GestureRadarDemo.cpp: 定义控制台应用程序的入口点。
// 需要手势轨迹识别模板生成软件，请联系frank.xiong@timevary.com

#include "stdafx.h"
#include "GestureRadarSDK.h"

#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

#pragma comment(lib,"GestureRadarSDK.lib")  
int recvRAW(float x, float y, float z)
{
	//cout <<" Data:" << x << "," << y << "," << z << endl;
	return 0;
}

int recvSwipeRecognise(const char* strName, float deltaDis)
{
	cout << strName << endl;
	return 0;
}

int recvTrailRecognise(const char* strName, double score)
{
	cout << strName << "," << score << endl;
	return 0;
}

int main()
{

	const char* strNames[] = { "Circle" };

	tvt_register_loop_callBack(true, true, 1, strNames, recvRAW, recvSwipeRecognise, recvTrailRecognise);

	int a;
	cin >> a;

	tvt_release_loop_callBack();
}
