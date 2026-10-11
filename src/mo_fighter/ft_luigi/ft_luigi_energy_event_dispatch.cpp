#include <types.h>

class soModuleAccesser;
struct LuigiObserverSignal {
    short flags;
};

extern "C" s16* fn_99_B198(s16*, const s16*);
extern "C" LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
extern "C" bool fn_99_B7DC(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B6F4(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B60C(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B524(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B43C(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B38C(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B2A4(void*, const LuigiObserverSignal*, soModuleAccesser*);
extern "C" bool fn_99_B1F4(void*, const LuigiObserverSignal*, soModuleAccesser*);

extern "C" void fn_99_AF5C(void* object, soModuleAccesser* accesser,
                          const LuigiObserverSignal* attributes) {
    u8* state = static_cast<u8*>(object);
    LuigiObserverSignal mask;
    s16 incoming = attributes->flags;
    LuigiObserverSignal copy1;
    LuigiObserverSignal copy3;
    LuigiObserverSignal copy5;
    LuigiObserverSignal copy7;
    LuigiObserverSignal copy6;
    LuigiObserverSignal copy4;
    LuigiObserverSignal copy2;
    LuigiObserverSignal copy0;
    fn_99_B198(&mask.flags, &incoming);
    fn_99_B874(&copy0, &mask);
    fn_99_B7DC(state + 0x208, &copy0, accesser);
    fn_99_B874(&copy1, &mask);
    fn_99_B6F4(state + 0x1CC, &copy1, accesser);
    fn_99_B874(&copy2, &mask);
    fn_99_B60C(state + 0x180, &copy2, accesser);
    fn_99_B874(&copy3, &mask);
    fn_99_B524(state + 0x138, &copy3, accesser);
    fn_99_B874(&copy4, &mask);
    fn_99_B43C(state + 0xF0, &copy4, accesser);
    fn_99_B874(&copy5, &mask);
    fn_99_B38C(state + 0x98, &copy5, accesser);
    fn_99_B874(&copy6, &mask);
    fn_99_B2A4(state + 0x64, &copy6, accesser);
    fn_99_B874(&copy7, &mask);
    fn_99_B1F4(state + 8, &copy7, accesser);
}
