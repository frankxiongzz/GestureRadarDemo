#pragma once
#include <iostream>
using namespace std;

//用户的回调函数定义
typedef int(__stdcall * CallBackHandle)(int x, int y, int reserve, int z);

//异步API，用户需要先注册回调函数
/*
Asynchronous API
Developer should register call back function first
*/
__declspec(dllexport) void __stdcall registerLoopCallBack(CallBackHandle callbackFunc);

//异步API，释放回调函数，释放线程资源
/*
Asynchronous API
Realease call back function
*/
__declspec(dllexport) void realeaseCallBack();

//同步API，找到工作的串口，并打开
/*
Synchronous  API
initial serial port and find working serial port
@return
true    initial success
false   initial failed
*/
__declspec(dllexport) bool initialHW();

//同步API，阻塞式的访问
/*
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
__declspec(dllexport) bool getRawData(int &x, int &y, int &reserve, int &z);


//同步API，释放串口
/*
Synchronous  API
realease serial port
*/
__declspec(dllexport) void realeaseHW();



