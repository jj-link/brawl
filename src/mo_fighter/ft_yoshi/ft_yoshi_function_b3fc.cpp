#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char arg);
};

extern "C" void fn_95_B3FC(soEventObserver<soAnimCmdEventObserver>* self, short id, int arg)
{
    self->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<signed char>(arg));
}
