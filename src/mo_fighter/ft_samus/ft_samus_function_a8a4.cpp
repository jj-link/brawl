#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char argument);
};

extern "C" void fn_94_A8A4(void* self, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* observer = reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(self);
    observer->addObserverSub(static_cast<long>(id), reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<signed char>(argument));
}
