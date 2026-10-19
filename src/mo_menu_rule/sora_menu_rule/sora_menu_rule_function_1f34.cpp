#include <types.h>
#pragma force_active on

extern "C" void fn_800B330C(void* a, int b, int c);
extern "C" void fn_801AAFF0(void* a, int b);
extern "C" void fn_801AB014(void* a, int b);

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

extern "C" void fn_18_1F34(SoraRule* self, int param2) {
    int flag = *(u8*)((char*)((void**)self->array[self->base + self->target])[3] + 0xD0) - 1;
    for (int i = 0; i < self->count; i++) {
        int value;
        if (i == self->target && param2 != 0) {
            value = self->value + 0x50;
            fn_800B330C(self->array[self->base + i], value, 1);
        } else {
            value = self->value + 0x64;
            fn_800B330C(self->array[self->base + i], value, 1);
        }
        void* ptr = self->array[self->base + i];
        fn_801AAFF0(((void**)ptr)[3], flag);
        fn_801AB014(((void**)ptr)[3], flag);
    }
}
