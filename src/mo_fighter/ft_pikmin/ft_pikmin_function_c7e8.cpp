#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char arg);
};

extern "C" void fn_113_C7E8(void* receiver, s16 id, int argument) {
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(receiver)->addObserverSub(static_cast<s16>(id), reinterpret_cast<soAnimCmdEventObserver*>(receiver), static_cast<s8>(argument));
}
