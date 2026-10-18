#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long l, T* observer, signed char c);
};

extern "C" void fn_99_8664(void* obs, short l, signed char c) {
    soEventObserver<soAnimCmdEventObserver>* self = reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(obs);
    self->addObserverSub(l, reinterpret_cast<soAnimCmdEventObserver*>(obs), c);
}
