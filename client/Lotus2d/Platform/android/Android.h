/********************************************************************
	created:	2012/10/25
	filename: 	Android.h
	author:		reedhong
	
	purpose:	����c����Android�Ľӿ�,��ʱ����֪�������c++��ʽд��
						����c����
*********************************************************************/

#ifndef __Lotus2d_Andriod_H__
#define __Lotus2d_Andriod_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const  char *AdapterAndroidClass;

// input
extern const char *AdapterAndroidClass_Method_setEditorVisibility ;
extern const char *AdapterAndroidClass_Method_getEditorText ;
extern const char *AdapterAndroidClass_Method_setEditorText ;
extern const char *AdapterAndroidClass_Method_setEditorExtent;
extern const char *AdapterAndroidClass_Method_setEditorPassword;
extern const char *AdapterAndroidClass_Method_setEditorInputMode;
extern const char *AdapterAndroidClass_Method_setEditorTextColor;
extern const char *AdapterAndroidClass_Method_setEditorMaxLength;


extern const char *AdapterAndroidClass_Method_sendSmsMessage;
extern const char *AdapterAndroidClass_Method_getSmsStatus;

extern const char *AdapterAndroidClass_Method_openurl;

extern const char *AdapterAndroidClass_Method_openAssetFileFD;

extern const char *AdapterAndroidClass_Method_terminateProcess;

extern const char *AdapterAndroidClass_Method_loginSucessNotify;
extern const char *AdapterAndroidClass_Method_updateClient;


extern JavaVM *g_JavaVM;
extern jclass g_classAndroid;//android adapter class 
extern jmethodID getMethodID(const char *methodName, const char *paramCode);
extern JNIEnv* getEnv();


#ifdef __cplusplus
}
#endif

#endif