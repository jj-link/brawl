#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(long id, T* observer, signed char arg);
};

extern "C" void fn_96_EFEC(void* receiver, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* self = (soEventObserver<soAnimCmdEventObserver>*)receiver;
    self->addObserverSub(static_cast<long>(id), (soAnimCmdEventObserver*)receiver, static_cast<signed char>(argument));
}
