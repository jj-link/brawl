#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver
{
public:
    void addObserverSub(long id, T* observer, signed char priority);
};

extern "C" void fn_120_95BC(void* self, s16 id, signed char priority)
{
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(self)->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(self), priority);
}
