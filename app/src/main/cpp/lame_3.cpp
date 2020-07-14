#include <jni.h>
#include "lame.h"
#include "lame.c"
#include <string.h>

extern "C"{
    JNIEXPORT jstring JNICALL
    Java_com_wlwoon_libso_LameManager_lameVersion(JNIEnv *env, jobject thiz) {
        // TODO: implement lameVersion()
        return env->NewStringUTF(get_lame_version());
    }

}

