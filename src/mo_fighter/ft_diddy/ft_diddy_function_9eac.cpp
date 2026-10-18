#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, s8 argument);
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
};

extern "C" void fn_115_9EAC(soEventObserver<soAnimCmdEventObserver>* self, s16 id, int argument) {
    self->addObserverSub(static_cast<long>(id), reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<s8>(argument));
}
