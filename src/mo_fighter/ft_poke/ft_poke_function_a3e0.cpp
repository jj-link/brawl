#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(long id, T* observer, signed char arg);
};

extern "C" void fn_116_A3E0(void* receiver, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* self =
        static_cast<soEventObserver<soAnimCmdEventObserver>*>(receiver);
    self->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(receiver), static_cast<s8>(argument));
}
