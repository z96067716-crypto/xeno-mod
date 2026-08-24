#include <jni.h>
#include <string>
#include <android/log.h>
#include <unistd.h>

#define TAG "XenoCheat"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

struct CheatConfig {
    bool isUnlocked;
    bool enemyOnlyESP;     // ВХ только на врагов
    bool antiCheatBypass;  // Защитная маскировка
};

CheatConfig config = {false, true, true};

extern "C" {

void initAntiCheatEvasion() {
    if (!config.antiCheatBypass) return;
    LOGD("Anti-cheat evasion layers applied. By tg @xenoCheatdelta");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    initAntiCheatEvasion();
    LOGD("Library loaded successfully! By tg @xenoCheatdelta");
    return JNI_VERSION_1_6;
}

JNIEXPORT jboolean JNICALL
Java_com_xenocheat_delta_ModMenu_nativeCheckKey(JNIEnv *env, jobject thiz, jstring jKey) {
    const char *keyChars = env->GetStringUTFChars(jKey, 0);
    std::string key(keyChars);
    env->ReleaseStringUTFChars(jKey, keyChars);

    if (key == "FREE" || key == "free") {
        config.isUnlocked = true;
        LOGD("Key accepted: FREE");
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
Java_com_xenocheat_delta_ModMenu_nativeShouldRenderESP(JNIEnv *env, jobject thiz, jint localTeam, jint targetTeam) {
    if (!config.enemyOnlyESP) {
        return JNI_TRUE;
    }
    return (localTeam != targetTeam) ? JNI_TRUE : JNI_FALSE;
}

}
