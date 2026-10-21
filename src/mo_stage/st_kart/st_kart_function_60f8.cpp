#pragma force_active on
typedef unsigned int u32;

extern "C" const float lbl_49_rodata_90[];
extern "C" char lbl_49_data_1BA8[];

struct Kart {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    u32 upper3C : 27;
    u32 flags3C : 5;
    u32 field40;
    char* field44;
    char* field48;
    u32 flags4C;
    char arr[8 * 7];
};

extern "C" {
void fn_49_621C(void*);
void fn_49_622C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
}

extern "C" void* fn_49_60F8(Kart* self) {
    self->x = lbl_49_rodata_90[0];
    self->y = lbl_49_rodata_90[0];
    self->z = lbl_49_rodata_90[0];
    self->flags3C = 0;
    self->field44 = lbl_49_data_1BA8;
    self->field48 = lbl_49_data_1BA8 + 0x48;
    self->flags4C &= 0x7FFFF;
    __construct_array(self->arr, fn_49_621C, fn_49_622C, 8, 7);
    return self;
}
