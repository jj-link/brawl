#pragma force_active on
#include <types.h>

struct SoraSelf {
    char pad[0x49];
    u8 b49;
    char pad1[1];
    u8 b4b;
    char pad2[0x58 - 0x4c];
    u32 i58;
};

extern "C" {
extern unsigned int lbl_27_bss_59C0;
extern char g_Network[];
int fn_8013E380(void*, u32);
void fn_27_254CE8(void (*)(void*));
}

extern "C" void fn_27_25522C(SoraSelf* self, u32 arg2) {
    if (self->b49 != 0 && lbl_27_bss_59C0 != 0) {
        self->i58 = arg2;
        int result = fn_8013E380(*(void**)(g_Network + 0x34), arg2 & 0xFF);
        if (result == 0) {
            self->i58 = arg2;
            self->b4b = 1;
            fn_27_254CE8(0);
        }
    }
}
