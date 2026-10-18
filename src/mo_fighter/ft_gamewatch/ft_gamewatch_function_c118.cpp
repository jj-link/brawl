#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char c);
};

extern "C" void fn_107_C118(soEventObserver<soAnimCmdEventObserver>* self, short id, signed char c) {
    self->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(self), c);
}
