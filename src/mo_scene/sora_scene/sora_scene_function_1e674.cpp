#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_sndSystem;
void fn_80073F84(void*, int);
void fn_1_1E92C(void*);

void fn_1_1E674(void* self) {
    *(u32*)((u8*)self + 0x28) = 0;
    *(u8*)((u8*)self + 0x60) = 0;
    *(u8*)((u8*)self + 0x61) = 0;
    fn_80073F84(g_sndSystem, 0);
    fn_1_1E92C(self);
}
}
