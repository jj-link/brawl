#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, soAnimCmdEventObserver* observer, signed char arg);
};

extern "C" void fn_123_9FD8(soEventObserver<soAnimCmdEventObserver>* self, short id, int arg)
{
    self->addObserverSub(static_cast<long>(id), reinterpret_cast<soAnimCmdEventObserver*>(self), static_cast<signed char>(arg));
}
