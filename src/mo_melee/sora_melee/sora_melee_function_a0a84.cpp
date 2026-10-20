#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_2B78;
void* __dt__16acCmdInterpreterFv(void*, short);
void __dt__6gfTaskFv(void*, int);
void* fn_27_9FC94(void*, s32);
void __dl__FPv(void*);

void* fn_27_A0A84(void* p, s32 n) {
    if (p != nullptr) {
        lbl_27_bss_2B78 = 0;
        void* q = (void*)((u8*)p + 0xfc);
        if (q != nullptr) {
            __dt__16acCmdInterpreterFv(q, 0);
        }
        fn_27_9FC94((u8*)p + 0xf8, -1);
        __dt__6gfTaskFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
