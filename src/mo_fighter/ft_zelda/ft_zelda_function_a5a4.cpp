#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(s32 id, T* observer, s8 argument);
};

extern "C" void fn_104_A5A4(void* self, s16 id, int argument) {
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(self)->addObserverSub(static_cast<s32>(id), reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<s8>(argument));
}
