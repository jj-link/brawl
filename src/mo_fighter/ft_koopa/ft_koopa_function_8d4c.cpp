#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char arg);
};

extern "C" void fn_102_8D4C(void* receiver, short id, int argument)
{
    soEventObserver<soAnimCmdEventObserver>* self = (soEventObserver<soAnimCmdEventObserver>*)receiver;
    self->addObserverSub(id, (soAnimCmdEventObserver*)receiver, (signed char)argument);
}
