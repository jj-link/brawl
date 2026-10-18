#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char argument);
};

extern "C" void fn_112_A598(void* receiver, short id, int argument) {
    ((soEventObserver<soAnimCmdEventObserver>*)receiver)->addObserverSub(id, (soAnimCmdEventObserver*)receiver, (signed char)argument);
}
