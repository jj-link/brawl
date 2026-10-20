#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_790D0[];
void* getManager__11soArchiveDbFUl(u32 idx);
void fn_80045E64(void* mgr, u32 arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_2B2A30(void* p, s32 flag) {
    if (p) {
        *(char**)((char*)p + 0x14) = lbl_27_data_790D0;
        void* mgr = getManager__11soArchiveDbFUl(2);
        fn_80045E64(mgr, *(u32*)((char*)p + 0xc));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
