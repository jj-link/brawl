#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char argument);
};

extern "C" void fn_109_8DC8(soEventObserver<soAnimCmdEventObserver>* self, short id, int argument) {
    self->addObserverSub(static_cast<long>(id), reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<signed char>(argument));
}
