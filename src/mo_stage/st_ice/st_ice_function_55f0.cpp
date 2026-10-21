#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern const float lbl_62_rodata_84;
extern char lbl_62_data_1A68[];

void fn_62_5714(void*);
void fn_62_5724(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
}

struct Obj {
    char pad0[0x28];
    float x, y, z;
    char pad34[8];
    u32 upper3c : 27;
    u32 lower3c : 5;
    char pad40[4];
    void* vt;
    void* calc;
    u32 upper4c : 13;
    u32 lower4c : 19;
    char entries[7][8];
};

extern "C" void* fn_62_55F0(Obj* self) {
    self->x = lbl_62_rodata_84;
    self->y = lbl_62_rodata_84;
    self->z = lbl_62_rodata_84;
    self->lower3c = 0;
    self->vt = lbl_62_data_1A68;
    self->calc = lbl_62_data_1A68 + 0x48;
    self->upper4c = 0;

    __construct_array(self->entries, fn_62_5714,
                      (void (*)(void*))fn_62_5724, 8, 7);

    return self;
}
