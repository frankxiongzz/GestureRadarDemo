#pragma once
#include <iostream>
#include <vector>
using namespace std;

//异步API，用户需要先注册回调函数
/*
Summary:
Asynchronous API
Developer should register call back function first

@param:
callbackRawDataFunc: user define address of function，raw data function
callbackRecognizedResultFunc: user define address of function，recognise data function
bStartRecognizing: begin to recognizing? if true, need input callbackRecognizedResultFunc address
strNames : recognizing data ***.dat, need our tool to establish module
@return
None
*/
extern "C" void __declspec(dllexport) __stdcall registerLoopCallBack(int(*callbackRawDataFunc)(int, int, int, int), int(*callbackRecognizedResultFunc)(const char *, double), bool bStartRecognizing, int nTemplateNum, const char *strTemplateNames[]);



//异步API，释放回调函数，释放线程资源
/*
Summary:
Asynchronous API
Realease call back function

@param:
None

@return
None
*/
extern "C" void __declspec(dllexport) releaseLoopCallBack();










//同步API，找到工作的串口，并打开，不建议同步的方式
/*
*Summary:
Synchronous  API
initial serial port and find working serial port, we do not suggest use it

*Parameters:
mscTimeOut User set read microsecond timeout for gesture radar
-1 wait forever

@return
true    initial success
false   initial failed
*/
extern "C" bool __declspec(dllexport) initialHW(int mscTimeOut);



//同步API，阻塞式的访问
/*

*Summary:
Synchronous  API
get raw data from gesture radar

@param:
int &x 传入x地址参数 x value address
int &y 传入y地址参数 y value address
int &reserve 传入reserve地址参数 reserve value address
int &z 传入z地址参数 z value address

@return
true    read success
false   read failed
*/
extern "C" bool __declspec(dllexport) getRawData(int &x, int &y, int &reserve, int &z);



//同步API，释放串口
/*
Summary: Synchronous  API
realease serial port

@param:
None

@return
None
*/
extern "C" void __declspec(dllexport) releaseHW();
