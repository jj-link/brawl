#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long, T*, signed char);
};

extern "C" void fn_101_CF68(soEventObserver<soAnimCmdEventObserver>* self, short l, signed char c)
{
    self->addObserverSub(l, reinterpret_cast<soAnimCmdEventObserver*>(self), c);
}
