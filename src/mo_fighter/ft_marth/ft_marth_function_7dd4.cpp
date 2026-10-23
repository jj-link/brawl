#pragma force_active on
class soAnimCmdEventObserver;

template <typename T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char argument);
};

extern "C" void fn_106_7DD4(soEventObserver<soAnimCmdEventObserver>* receiver, short id, int argument) {
    receiver->addObserverSub(id, reinterpret_cast<soAnimCmdEventObserver*>(receiver), static_cast<signed char>(argument));
}
