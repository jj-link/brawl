#pragma force_active on
#include <types.h>

extern "C" void fn_801AB038(void* p, int v);
extern "C" void fn_801AB0B8(void* p, int v);
extern u8 lbl_10_rodata_6AC[];

extern "C" void fn_10_1450C(char* self) {
    char* inner;
    u8* idx = lbl_10_rodata_6AC;
    char* base = self;
    char* slot = self + 0x154;
    s32 i = 0;
    do {
        u32 k;
        char* obj;
        if (i >= 0 && i < 7) {
            k = *idx;
        } else {
            k = 0x28;
        }
        obj = *(char**)(self + k * 4 + 0xB0);
        if (obj != 0) {
            inner = *(char**)(obj + 0x10);
            *(u32*)(base + 0x15C) = *(u32*)(inner + 0xD4);
            *(char**)(inner + 0xD4) = slot;
            fn_801AB038(inner, 4);
            fn_801AB0B8(inner, 1);
        }
        i++;
        idx++;
        base += 0xC;
        slot += 0xC;
    } while (i < 7);
}
