#include <types.h>
#pragma force_active on

extern "C" {
void fn_800BA2E8();
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_1_135E0(void*, int);
void fn_800B330C(void*, void*, int);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void setUpdateRate__16gfModelAnimationFf(void*, float);
extern char lbl_18_data_6D0[];
extern char lbl_18_data_700[];
extern float lbl_18_rodata_38;
}

struct Model {
    u8 _00[0xD0];
    u8 flag;
};

struct Item {
    u8 _00[0x0C];
    Model* model;
    u8 _10[0x04];
    void* anim;
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

extern "C" void fn_18_1AE0(SoraRule* self, int arg1, int arg2) {
    fn_800BA2E8();
    if (arg2 != 0) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        char* p = (char*)__dynamic_cast(*(void**)(mgr + 4), 4, lbl_18_data_6D0, lbl_18_data_700, 0);
        fn_1_135E0(p, arg1);
        return;
    }
    for (int i = 0; i < self->count; i++) {
        if (i == self->target) {
            fn_800B330C(self->array[self->base + i], self->value + 0x28, 1);
            Item* item = self->array[self->base + i];
            int flag = item->model->flag + 1;
            fn_801AAFF0(item->model, flag);
            fn_801AB014(item->model, flag);
        } else {
            fn_800B330C(self->array[self->base + i], self->value + 0x78, 1);
        }
        setUpdateRate__16gfModelAnimationFf(self->array[self->base + i]->anim, lbl_18_rodata_38);
    }
    char* mgr2 = (char*)getInstance__14gfSceneManagerFv();
    char* q = (char*)__dynamic_cast(*(void**)(mgr2 + 4), 4, lbl_18_data_6D0, lbl_18_data_700, 0);
    *(int*)(q + 0xAB0) = arg1;
    *(int*)(q + 0xAB4) = 2;
}
