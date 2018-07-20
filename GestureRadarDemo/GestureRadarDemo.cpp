﻿// GestureRadarDemo.cpp: 定义控制台应用程序的入口点。
// 需要手势轨迹识别模板生成软件，请联系frank.xiong@timevary.com

#include "stdafx.h"
#include "GestureRadarSDK.h"

#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

#pragma comment(lib,"GestureRadarSDK.lib")  


int recvRAW(int x, int y, int reserve, int z)
{
	cout << x << "," << y << "," << z << endl;
	return 0;
}

int recvRecognise(const char *strName, double score)
{
	cout << strName << "," << score << endl;
	return 0;
}


int main()
{

	/*
		First Way : Asynchronous call, We strongly recommend this way
		Developer register self define function
		recvRAW receive X, Y ,Z position of hand
		recvRecognise receive result of hand trajectory recognizing
		if you want to get TemplateTool, please contact me
	*/
	const char *strNames[] = { "Circle", "Triangle" };
	//make sure that Circle.dat and Triangle.dat in the same directory with GestureRadarSDK.lib
	registerLoopCallBack(recvRAW, recvRecognise, true, 2, strNames);

	int a;
	cin >> a;

	releaseLoopCallBack();
	return 0;



	/*
	Second Way : Synchronous mode
	1. inial hw
	2. get data
	3. release hw
	*/
	//if (initialHW(-1))
	//{
	//	while (true)
	//	{
	//		int x, y, reserver, z;
	//		getRawData(x, y, reserver, z);
	//		cout << "X: " << x << " Y:" << y << " reserve:" << reserver << " Z:" << z << endl;
	//	}
	//}
	//releaseHW();
	//getchar();
}
