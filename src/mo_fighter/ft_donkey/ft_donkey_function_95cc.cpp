#include <types.h>
#pragma force_active on

class soAnimCmdEventObserver;

template <class T>
class soEventObserver
{
public:
    void addObserverSub(long id, T* observer, signed char argument);
};

extern "C" void fn_92_95CC(soEventObserver<soAnimCmdEventObserver>* receiver, s16 id, int argument)
{
    receiver->addObserverSub(static_cast<long>(id), reinterpret_cast<soAnimCmdEventObserver*>(receiver), static_cast<signed char>(argument));
}
