#include <so/event/so_event_presenter.h>
#include <types.h>

class soAnimCmdEventObserver;

// Import the existing shared binary instance with the original observer ABI.
// No instance is created here; every declared operation remains external.
template <>
class soEventObserver<soAnimCmdEventObserver> {
public:
    virtual void addObserver(s16 manageId, s8 argument);
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;
    void addObserverSub(s32 manageId, soAnimCmdEventObserver* observer, s8 argument);
};
static_assert(sizeof(soEventObserver<soAnimCmdEventObserver>) == 0xC,
              "Imported observer instance has the original ABI");

extern "C" void fn_27_D38D4(void* object, s32 manageId, void* observer, s8 unitId);

extern "C" void fn_111_8448(soEventObserver<soAnimCmdEventObserver>* observer,
                            s16 manageId, s8 unitId) {
    observer->addObserverSub(manageId,
                             reinterpret_cast<soAnimCmdEventObserver*>(observer),
                             unitId);
}

extern "C" void fn_111_845C(void* observer, s16 manageId, s8 unitId) {
    fn_27_D38D4(observer, manageId, observer, unitId);
}
