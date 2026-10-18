#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <typename T> class soEventObserver {
public:
    void addObserverSub(s32 manageId, T* observer, s8 priority);
};

extern "C" void fn_98_9BFC(void* observer, s16 manageId, s8 priority) {
    soEventObserver<soAnimCmdEventObserver>* self = (soEventObserver<soAnimCmdEventObserver>*)observer;
    self->addObserverSub(manageId, (soAnimCmdEventObserver*)observer, priority);
}
