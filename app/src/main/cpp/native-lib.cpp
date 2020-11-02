#include <jni.h>
#include <string>
#include "InfiniTAMApp.h"
#include<unistd.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_tinyxr_xr_infinitam_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMRenderer_InitGL(JNIEnv *env, jclass clazz) {
    (InfiniTAMApp::Instance())->InitGL();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMRenderer_ResizeGL(JNIEnv *env, jclass clazz, jint x,
                                                        jint y) {
    (InfiniTAMApp::Instance())->ResizeGL(x,y);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMRenderer_RenderGL(JNIEnv *env, jclass clazz) {
    (InfiniTAMApp::Instance())->RenderGL();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMProcessor_StartProcessing(JNIEnv *env, jclass clazz,
                                                                jint use_live_camera) {
    (InfiniTAMApp::Instance())->StartProcessing(use_live_camera);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMProcessor_ProcessFrame(JNIEnv *env, jclass clazz) {
    return (InfiniTAMApp::Instance())->ProcessFrame()?1:0;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMProcessor_StopProcessing(JNIEnv *env, jclass clazz) {
    (InfiniTAMApp::Instance())->StopProcessing();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMProcessor_toggleRecordingMode(JNIEnv *env, jclass clazz) {
    (InfiniTAMApp::Instance())->toggleRecordingMode();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMProcessor_getAverageTime(JNIEnv *env, jclass clazz) {
    return (InfiniTAMApp::Instance())->getAverageTime();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_tinyxr_xr_infinitam_InfiniTAMApplication_InitializeNativeApp(JNIEnv *env, jclass clazz,
                                                                      jstring java_libdir) {
    const char *native_libdir = env->GetStringUTFChars(/*env,*/ java_libdir, NULL);
    //chdir(native_libdir);
    InfiniTAMApp::Instance();
    env->ReleaseStringUTFChars(/*env,*/ java_libdir, native_libdir);
}