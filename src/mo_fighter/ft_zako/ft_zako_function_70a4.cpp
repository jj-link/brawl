#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, T* observer, signed char flag);
};

extern "C" void fn_126_70A4(void* self, short id, int arg)
{
    ((soEventObserver<soAnimCmdEventObserver>*)self)->addObserverSub(id, (soAnimCmdEventObserver*)self, (signed char)arg);
}
