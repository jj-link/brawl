#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* owner, signed char arg);
};

extern "C" void fn_105_D8BC(void* self, short id, int arg)
{
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(self)->addObserverSub(
        id,
        static_cast<soAnimCmdEventObserver*>(self),
        static_cast<signed char>(arg));
}
