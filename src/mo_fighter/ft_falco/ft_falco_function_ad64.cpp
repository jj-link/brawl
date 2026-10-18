#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char argument);
};

extern "C" void fn_108_AD64(void* receiver, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* self = (soEventObserver<soAnimCmdEventObserver>*)receiver;
    self->addObserverSub(id, (soAnimCmdEventObserver*)receiver, (signed char)argument);
}
