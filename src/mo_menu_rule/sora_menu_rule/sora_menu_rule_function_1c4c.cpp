#include <types.h>
#pragma force_active on

extern "C" void fn_800B330C(void* a, int b, int c);
extern "C" void fn_801AAFF0(void* a, int b);
extern "C" void fn_801AB014(void* a, int b);
extern "C" void fn_800B753C(void* a, float b);
extern "C" float lbl_18_rodata_3C;

struct SoraRule {
    u8 _000[0x42];
    u16 target;
    u8 _044[0x5FC];
    u16 count;
    u16 _642;
    int base;
    int value;
    void** array;
};

extern "C" void fn_18_1C4C(SoraRule* self, int param2) {
    for (int i = 0; i < self->count; i++) {
        if (i == self->target) {
            fn_800B330C(self->array[self->base + i], self->value, 1);
            void* ptr = self->array[self->base + i];
            int flag = *(u8*)((char*)*(void**)((char*)ptr + 0x0C) + 0xD0) + 1;
            fn_801AAFF0(*(void**)((char*)ptr + 0x0C), flag);
            fn_801AB014(*(void**)((char*)ptr + 0x0C), flag);
        } else {
            fn_800B330C(self->array[self->base + i], self->value + 0x14, 1);
        }
        if (param2 == 0) {
            fn_800B753C(self->array[self->base + i], lbl_18_rodata_3C);
        }
    }
}