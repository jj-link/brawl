#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char prio);
};

extern "C" void fn_117_A28C(soEventObserver<soAnimCmdEventObserver>* self, short id, signed char prio)
{
    self->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(self), prio);
}
