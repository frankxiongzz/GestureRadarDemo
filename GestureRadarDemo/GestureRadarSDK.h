#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
Summary:异步API，用户需要先注册回调函数

@param:

@return

*/
extern "C" void __declspec(dllexport) __stdcall tvt_register_loop_callBack(
	bool bRecognizeSwipe,
	bool bRecognizeTrail,
	int nTemplateNum,
	const char* strTemplateNames[],
	int(*callbackRawDataFunc)(float, float, float),
	int(*callbackSwipeRecognizeFunc)(const char*, float),
	int(*callbackTrailRecognizeFunc)(const char*, double)
);



/*
Summary: 释放回调函数，释放线程资源

@param:


@return
*/
extern "C" void __declspec(dllexport) tvt_release_loop_callBack();

/*
Summary: 设置识别的距离

@param:


@return
*/
extern "C" void __declspec(dllexport) tvt_set_recognizing_range(int minZ, int maxZ);


/*
Summary: 设置识别间隔时间

@param:
ms 间隔时间 毫秒

@return
*/
extern "C" void __declspec(dllexport) tvt_set_recognizing_interval_time(int ms);

/*
Summary: 获取识别间隔时间

@param:
ms None

@return
*/
extern "C" int __declspec(dllexport) tvt_get_recognizing_interval_time();


/*
Summary: 下面都是进行识别的参数阈值

@param:
ms None

@return
*/
extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_left_threshold(int leftThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_left_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_right_threshold(int rightThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_right_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_up_threshold(int upThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_up_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_down_threshold(int downThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_down_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_push_threshold(int pushThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_push_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_release_threshold(int releaseThreshold);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_release_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_circle_threshold(int accumulateCircle);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_circle_threshold();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_swipe_sampling_num(int swipeSamplingNum);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_swipe_sampling_num();

extern "C" void __declspec(dllexport) tvt_set_swipe_recognizing_drop_back_time(int millisecondDropBackTime);
extern "C" int __declspec(dllexport) tvt_get_swipe_recognizing_drop_back_time();

extern "C" bool __declspec(dllexport) tvt_write_raw_data(unsigned char* rawData, int rawDataLen);


extern "C" void __declspec(dllexport) tvt_set_swipe_x_weight(float weight);
extern "C" float __declspec(dllexport) tvt_get_swipe_swipe_x_weight();

extern "C" void __declspec(dllexport) tvt_set_swipe_y_weight(float weight);
extern "C" float __declspec(dllexport) tvt_get_swipe_swipe_y_weight();

extern "C" void __declspec(dllexport) tvt_set_swipe_z_weight(float weight);
extern "C" float __declspec(dllexport) tvt_get_swipe_swipe_z_weight();