#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, s8 argument);
};

extern "C" void fn_122_F324(void* receiver, s16 id, int argument) {
    soEventObserver<soAnimCmdEventObserver>* self =
        reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(receiver);
    self->addObserverSub(static_cast<long>(id), static_cast<soAnimCmdEventObserver*>(receiver),
                         static_cast<s8>(argument));
}
