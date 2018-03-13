#pragma once
#include <iostream>
using namespace std;

//�û��Ļص���������
typedef int(__stdcall * CallBackHandle)(int x, int y, int reserve, int z);


//�첽API���û���Ҫ��ע��ص�����
/*
Asynchronous API
Developer should register call back function first
*/
__declspec(dllexport) void __stdcall registerLoopCallBack(CallBackHandle callbackFunc);



//�첽API���ͷŻص��������ͷ��߳���Դ
/*
Asynchronous API
Realease call back function
*/
__declspec(dllexport) void releaseCallBack();



//ͬ��API���ҵ������Ĵ��ڣ�����
/*
Synchronous  API
initial serial port and find working serial port

*Parameters:

*   mscTimeOut User set read microsecond timeout for gesture radar
-1 wait forever
@return
true    initial success
false   initial failed
*/
__declspec(dllexport) bool initialHW(int mscTimeOut);



//ͬ��API������ʽ�ķ���
/*

*Summary:
Synchronous  API
get raw data from gesture radar

@param:
int &x ����x��ַ���� x value address
int &y ����y��ַ���� y value address
int &reserve ����reserve��ַ���� reserve value address
int &z ����z��ַ���� z value address

@return
true    read success
false   read failed
*/
__declspec(dllexport) bool getRawData(int &x, int &y, int &reserve, int &z);


//ͬ��API���ͷŴ���
/*
Summary: Synchronous  API
realease serial port
*/
__declspec(dllexport) void releaseHW();
