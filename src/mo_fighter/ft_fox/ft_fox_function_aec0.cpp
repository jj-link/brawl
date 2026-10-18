#include <types.h>
#pragma force_active on

struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(long id, T* observer, s8 argument);
};

extern "C" void fn_97_AEC0(void* receiver, s16 id, int argument) {
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(receiver)->addObserverSub(
        static_cast<long>(id),
        reinterpret_cast<soAnimCmdEventObserver*>(receiver),
        static_cast<s8>(argument));
}
