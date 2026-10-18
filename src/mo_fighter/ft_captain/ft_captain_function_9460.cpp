#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long, T*, signed char);
};

extern "C" void fn_100_9460(soEventObserver<soAnimCmdEventObserver>* self, short a, signed char b) {
    self->addObserverSub(a, reinterpret_cast<soAnimCmdEventObserver*>(self), b);
}
