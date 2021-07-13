//
// Created by Marc Rousavy on 13.07.21.
//

#pragma once

#include <jni.h>
#include <fbjni/fbjni.h>

#include <memory>

namespace expo {

using namespace facebook;

class JAVManager : public jni::HybridClass<JAVManager> {
public:
    static auto constexpr kJavaDescriptor = "Lexpo/modules/av/AVManager;";
    static auto constexpr TAG = "JAVManager";
    static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject> jThis);
    static void registerNatives();

    void installJSIBindings();

private:
    friend HybridBase;
    jni::global_ref<JAVManager::javaobject> javaPart_;

    explicit JAVManager(jni::alias_ref<JAVManager::jhybridobject> jThis) :
            javaPart_(jni::make_global(jThis))
    {}
};

} // namespace expo