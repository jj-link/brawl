#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8042E980[];
extern void* lbl_805A0110;
void fn_8005AD04();
void fn_8005BB98(void* base, void* node);
void __dl__FPv(void* p);
}

extern "C" void* fn_8005A820(void* self, s32 del) {
    if (self) {
        *(char**)((char*)self + 0x48) = lbl_8042E980;
        if (lbl_805A0110 == 0) {
            fn_8005AD04();
        }
        fn_8005BB98((char*)lbl_805A0110, self);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
