#pragma force_active on
extern "C" {
extern const float lbl_47_rodata_70;
extern char lbl_47_data_1AE8[];

void fn_47_4248(void*);
void fn_47_4258(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

struct St47Obj {
    char pad00[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int : 27;
    unsigned int flags3c : 5;
    unsigned int field40;
    void* field44;
    void* field48;
    unsigned int flags4c : 13;
    unsigned int : 19;
    char array50[7 * 8];
};

extern "C" St47Obj* fn_47_4124(St47Obj* self) {
    self->x = lbl_47_rodata_70;
    self->y = lbl_47_rodata_70;
    self->z = lbl_47_rodata_70;
    self->flags3c = 0;
    self->field44 = lbl_47_data_1AE8;
    self->field48 = lbl_47_data_1AE8 + 0x48;
    self->flags4c = 0;
    __construct_array(self->array50, fn_47_4248, fn_47_4258, 8, 7);
    return self;
}
