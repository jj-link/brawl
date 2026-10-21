#pragma force_active on
#include <types.h>

extern "C" void fn_801AB038(void* p, int v);
extern "C" void fn_801AB0B8(void* p, int v);
extern "C" u8 lbl_10_rodata_2F4[];

extern "C" void fn_10_C260(u8* arg0) {
    void* m;
    u8* tbl = lbl_10_rodata_2F4;
    u8* elem = arg0;
    u8* slot = arg0 + 0x50C;
    s32 i = 0;
    do {
        s32 idx;
        if (i >= 0 && i < 0xF) {
            idx = *tbl;
        } else {
            idx = 0xBC;
        }
        void* t = *(void**)(arg0 + idx * 4 + 0x13C);
        if (t != nullptr) {
            m = *(void**)((u8*)t + 0x10);
            *(u32*)(elem + 0x514) = *(u32*)((u8*)m + 0xD4);
            *(u8**)((u8*)m + 0xD4) = slot;
            fn_801AB038(m, 4);
            fn_801AB0B8(m, 1);
        }
        tbl++;
        i++;
        elem += 0xC;
        slot += 0xC;
    } while (i < 0xF);
}
