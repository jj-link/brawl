#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(long id, T* observer, signed char argument);
};

extern "C" void fn_121_AE08(void* self, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* owner = static_cast<soEventObserver<soAnimCmdEventObserver>*>(self);
    owner->addObserverSub(static_cast<long>(id), static_cast<soAnimCmdEventObserver*>(self), static_cast<s8>(argument));
}
