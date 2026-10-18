#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver
{
public:
    void addObserverSub(long id, T *observer, signed char argument);
};

extern "C" void fn_93_AE0C(void *receiver, s16 id, int argument)
{
    soEventObserver<soAnimCmdEventObserver> *self = (soEventObserver<soAnimCmdEventObserver> *)receiver;
    self->addObserverSub((long)id, (soAnimCmdEventObserver *)receiver, (signed char)argument);
}
