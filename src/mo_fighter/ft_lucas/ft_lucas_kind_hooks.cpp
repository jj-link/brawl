#include <ft/fighter.h>

extern "C" ftKind fn_114_CB68(const Fighter* fighter) {
    return *reinterpret_cast<const ftKind*>(reinterpret_cast<const char*>(fighter) + 0x110);
}

extern "C" ftKind fn_114_CB70(Fighter* fighter) {
    return fighter->getFtKind();
}

extern "C" u32 fn_114_CB80(void*) { return 0; }

// The original optional hooks below are single-instruction returns.
extern "C" void fn_114_CB88(void*) { }
extern "C" void fn_114_CB8C(void*) { }
extern "C" void fn_114_CB90(void*) { }
extern "C" void fn_114_CB94(void*) { }
extern "C" u32 fn_114_CB98(void*) { return 0; }
extern "C" u32 fn_114_CBA0(void*) { return 0; }
extern "C" void fn_114_CBA8(void*) { }
extern "C" void fn_114_CBAC(void*) { }
extern "C" void fn_114_CBB0(void*) { }
extern "C" void fn_114_CBB4(void*) { }
extern "C" void fn_114_CBB8(void*) { }
