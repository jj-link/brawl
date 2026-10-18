#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char flag);
};

extern "C" void fn_118_9FC0(soAnimCmdEventObserver* observer, short id, signed char flag)
{
    soEventObserver<soAnimCmdEventObserver>* self = (soEventObserver<soAnimCmdEventObserver>*)observer;
    self->addObserverSub(id, observer, flag);
}
