#pragma force_active on
typedef signed char s8;
typedef short s16;

class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    void addObserverSub(long id, soAnimCmdEventObserver* observer, s8 priority);
};

extern "C" void fn_110_943C(soAnimCmdEventObserver* self, s16 id, s8 priority)
{
    ((soEventObserver<soAnimCmdEventObserver>*)self)->addObserverSub(id, self, priority);
}
