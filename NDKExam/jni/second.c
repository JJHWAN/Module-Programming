#include <jni.h>
#include "android/log.h"

#define LOG_TAG "MyTag"
#define LOGV(...)   __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)

extern int first(int x,int y);

jint JNICALL Java_org_example_ndk_NDKExam_add(JNIEnv *env, jobject this, jint x, jint y)
{
	LOGV("log test %d", 1234);
	return first(x, y);
}

jint JNICALL Java_org_example_ndk_NDKExam_mul(JNIEnv *env, jobject this)
{
	LOGV("log test %d", 1234);
	jclass cls = (*env)->GetObjectClass(env, this);
	jfieldID fidNumber = (*env)->GetStaticFieldID(env, cls, "x", "I");
	jint x = (*env)->GetStaticIntField(env, this, fidNumber);

	fidNumber = (*env)->GetStaticFieldID(env, cls, "y", "I");
	jint y = (*env)->GetStaticIntField(env, this, fidNumber);

	return (jint)(x*y);
}


void JNICALL Java_org_example_ndk_NDKExam_testString(JNIEnv *env, jobject this, jstring string)
{
	const char *str=(*env)->GetStringUTFChars( env, string, 0);
	jint len = (*env)->GetStringUTFLength( env, string );
	LOGV("native testString len %d", len);
	LOGV("native testString %s", str);
	
	(*env)->ReleaseStringUTFChars( env, string, str );	
}
