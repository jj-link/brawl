#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_51_rodata_90;
extern char lbl_51_data_2450[];
void fn_51_5ACC(void);
void* fn_51_5ADC(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct Object {
    char pad00[0x28];
    float x, y, z;
    char pad34[8];
    u32 keep3c : 27;
    u32 flags3c : 5;
    char pad40[4];
    void* table44;
    void* table48;
    u32 flags4c : 13;
    u32 keep4c : 19;
    char array[56];
};

extern "C" void* fn_51_59A8(Object* self) {
    self->x = lbl_51_rodata_90;
    self->y = lbl_51_rodata_90;
    self->z = lbl_51_rodata_90;
    self->flags3c = 0;
    self->table44 = lbl_51_data_2450;
    self->table48 = lbl_51_data_2450 + 0x48;
    self->flags4c = 0;
    __construct_array(self->array, (void (*)(void*))fn_51_5ACC,
                      (void (*)(void*))fn_51_5ADC, 8, 7);
    return self;
}
