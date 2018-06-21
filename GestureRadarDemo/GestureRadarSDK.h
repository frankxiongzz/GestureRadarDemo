#pragma once
#include <iostream>
#include <vector>
using namespace std;

//�첽API���û���Ҫ��ע��ص�����
/*
Summary:
Asynchronous API
Developer should register call back function first

@param:
callbackRawDataFunc: user define address of function��raw data function
callbackRecognizedResultFunc: user define address of function��recognise data function
bStartRecognizing: begin to recognizing? if true, need input callbackRecognizedResultFunc address
strNames : recognizing data ***.dat, need our tool to establish module
@return
None
*/
extern "C" void __declspec(dllexport) __stdcall registerLoopCallBack(int(*callbackRawDataFunc)(int, int, int, int), int(*callbackRecognizedResultFunc)(const char *, double), bool bStartRecognizing, int nTemplateNum, const char *strTemplateNames[]);



//�첽API���ͷŻص��������ͷ��߳���Դ
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










//ͬ��API���ҵ������Ĵ��ڣ����򿪣�������ͬ���ķ�ʽ
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
extern "C" bool __declspec(dllexport) getRawData(int &x, int &y, int &reserve, int &z);



//ͬ��API���ͷŴ���
/*
Summary: Synchronous  API
realease serial port

@param:
None

@return
None
*/
extern "C" void __declspec(dllexport) releaseHW();
