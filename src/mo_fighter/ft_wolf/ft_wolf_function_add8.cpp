#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char arg);
};

extern "C" void fn_125_ADD8(soEventObserver<soAnimCmdEventObserver>* self, s16 id, int argument)
{
    self->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<signed char>(argument));
}
