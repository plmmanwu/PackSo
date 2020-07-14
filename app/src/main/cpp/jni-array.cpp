#include <jni.h>
#include <jni.h>
//#include <int>

extern "C" JNIEXPORT jint JNICALL
Java_com_wlwoon_packso_MainActivity_sumArray(JNIEnv* env, jobject thiz,
jintArray arr
){
    jsize len = env->GetArrayLength(arr);
    int buf[len],sum=0;
    env->GetIntArrayRegion(arr, 0, len, buf);
    for (int i = 0; i < len; ++i) {
        sum += buf[i];
    }
    return sum;
}

extern "C"
JNIEXPORT jstringextern "C"
JNIEXPORT jstring
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_wlwoon_libso_LameManager_lameVersion(JNIEnv *env, jobject thiz) {
    // TODO: implement lameVersion()
}