#include <so/event/so_event_presenter.h>

class soAnimCmdEventObserver;

// The original shared module owns this concrete observer instantiation.
// Declare its existing interface and layout without emitting its algorithms.
template <>
class soEventObserver<soAnimCmdEventObserver> {
public:
    virtual void addObserver(s16 manageId, s8 argument);
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;
    void addObserverSub(s32 manageId, soAnimCmdEventObserver* observer, s8 argument);
};
static_assert(sizeof(soEventObserver<soAnimCmdEventObserver>) == 12,
              "Shared observer instantiation ABI mismatch");

extern "C" void fn_27_D38D4(void* receiver, s16 id, void* owner, s8 argument);
extern "C" void fn_27_D3E88(void* receiver, s16 id, void* owner, s8 argument);
extern "C" void fn_27_D46B8(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_114_C9A4(soAnimCmdEventObserver* observer, s16 id, int argument) {
    reinterpret_cast<soEventObserver<soAnimCmdEventObserver>*>(observer)
        ->addObserverSub(id, observer, static_cast<s8>(argument));
}

extern "C" void fn_114_C9B8(void* receiver, s16 id, int argument) {
    fn_27_D38D4(receiver, id, receiver, static_cast<s8>(argument));
}

extern "C" void fn_114_C9CC(void*) { }

extern "C" u8 fn_114_C9D0(const void* object) {
    return static_cast<const u8*>(object)[0x44];
}

extern "C" void fn_114_C9D8(void*) { }

extern "C" void fn_114_C9DC(void* receiver, s16 id, int argument) {
    fn_27_D3E88(receiver, id, receiver, static_cast<s8>(argument));
}

extern "C" void fn_114_C9F0(void* receiver, s16 id, int argument) {
    fn_27_D46B8(receiver, id, receiver, static_cast<s8>(argument));
}
