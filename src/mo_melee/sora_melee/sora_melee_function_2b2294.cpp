#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_790B0[];
void* getManager__11soArchiveDbFUl(u32);
void fn_80045E64(void*, u32);
void freeGroup__9sndSystemFii(void*, s32, s32);
void __dl__FPv(void*);
extern void* g_sndSystem;
}

extern "C" void* fn_27_2B2294(void* p, s32 flag) {
    if (p) {
        *(char**)((char*)p + 0x2c) = lbl_27_data_790B0;
        fn_80045E64(getManager__11soArchiveDbFUl(2), *(u32*)((char*)p + 0x18));
        if (*(u32*)((char*)p + 0x14) != 0xffff) {
            void* m = getManager__11soArchiveDbFUl(2);
            fn_80045E64(m, *(u32*)((char*)p + 0x14));
        }
        fn_80045E64(getManager__11soArchiveDbFUl(2), *(u32*)((char*)p + 0x10));
        if ((u32)(*(u32*)((char*)p + 0x1c) + 0x10000) != 0xffff) {
            s32 g = *(s32*)((char*)p + 0x20);
            if (g >= 0) {
                freeGroup__9sndSystemFii(g_sndSystem, g, 0);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
