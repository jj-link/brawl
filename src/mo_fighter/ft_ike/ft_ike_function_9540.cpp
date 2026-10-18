#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(s32 id, T* observer, s8 argument);
};

extern "C" void fn_119_9540(void* receiver, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* self = reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(receiver);
    self->addObserverSub(static_cast<s32>(id), reinterpret_cast<soAnimCmdEventObserver*>(receiver), static_cast<s8>(argument));
}
