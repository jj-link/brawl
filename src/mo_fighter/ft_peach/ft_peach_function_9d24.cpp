#pragma force_active on
struct soAnimCmdEventObserver;

template <class T>
struct soEventObserver {
    void addObserverSub(long id, T* observer, signed char flag);
};

struct soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
};

extern "C" void fn_103_9D24(soAnimCmdEventObserver* self, short id, signed char flag)
{
    static_cast<soEventObserver<soAnimCmdEventObserver>*>(self)->addObserverSub(id, self, flag);
}
