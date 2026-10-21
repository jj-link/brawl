#include <types.h>
#pragma force_active on

struct IList {
    virtual void f0();
    virtual void* getId(s32 index);
    virtual void f2();
    virtual s32 getCount();
};

extern "C" void fn_27_112FD0(void* p);
extern "C" void fn_27_11A440(void* p);
extern "C" void fn_27_122078(s32 p);
extern "C" u32 fn_8004E958(s32 p);
extern "C" s32 g_GameGlobal;
extern "C" s32 g_ftSlotManager;

extern "C" void fn_27_10C3C4(char* self) {
    u8 v = *(u8*)(self + 0x6B);
    if (v != 0) {
        *(u8*)(self + 0x6B) = v - 1;
    }
    if (fn_8004E958(g_GameGlobal) == 1) {
        fn_27_122078(g_ftSlotManager);
        fn_27_11A440(*(void**)(self + 0x154));
        s32 count = ((IList*)(*(char**)(self + 0x154) + 8))->getCount();
        for (s32 i = 0; i < count; i++) {
            char* p = (char*)((IList*)(*(char**)(self + 0x154) + 8))->getId(i);
            fn_27_112FD0(*(void**)(*(char**)p + 0x28));
        }
    }
}
