#include <types.h>
#pragma force_active on

extern "C" void fn_18_17B0(void*, int, int, float);
extern "C" void fn_800B330C(void*, void*, int);
extern "C" void fn_800B753C(void*, float);
extern "C" void fn_801AAFF0(void*, int);
extern "C" void fn_801AB014(void*, int);

struct Model {
    u8 _00[0xD0];
    u8 flag;
};

struct Item {
    u8 _00[0x0C];
    Model* model;
    u8 _10[0x0C];
    int field;
};

struct SoraRule {
    u8 _000[0x42];
    u16 target;
    u8 _044[0x5FC];
    u16 count;
    u16 _642;
    int base;
    u8* value;
    Item** array;
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
            fn_800B753C(self->array[self->base + i], 9.0f);
        }
    }
}

extern "C" void fn_18_1D48(SoraRule* self, int newTarget, int updateAll) {
    fn_800B330C(self->array[self->base + newTarget], self->value + 0x14, 1);

    self->array[self->base + newTarget]->field = 0;

    fn_18_17B0(self, self->base + newTarget, self->value[0x24], 9.0f);

    Item* item = self->array[self->base + newTarget];
    int flag = item->model->flag;

    if (updateAll != 0) {
        for (int i = 0; i < self->count; i++) {
            if (i == self->target) {
                fn_800B330C(self->array[self->base + i], self->value + 0x3C, 1);
                item = self->array[self->base + i];
                fn_801AAFF0(item->model, flag);
                fn_801AB014(item->model, flag);
            } else {
                fn_800B753C(self->array[self->base + i], 9.0f);
                item = self->array[self->base + i];
                fn_801AAFF0(item->model, flag - 1);
                fn_801AB014(item->model, flag - 1);
            }
        }
    } else {
        fn_801AAFF0(item->model, flag - 1);
        fn_801AB014(item->model, flag - 1);

        fn_800B330C(self->array[self->base + self->target], self->value + 0x3C, 1);
        Item* it = self->array[self->base + self->target];
        fn_801AAFF0(it->model, flag);
        fn_801AB014(it->model, flag);
    }
}
