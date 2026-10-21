#pragma force_active on
extern "C" {
extern const float lbl_68_rodata_D4;
extern char lbl_68_data_2580[];

void fn_68_5E10(void*);
void fn_68_5E20(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

struct Object {
    char pad0[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int preserved3C : 27;
    unsigned int flags3C : 5;
    char pad40[4];
    void* a;
    void* b;
    unsigned int flags4C : 13;
    unsigned int preserved4C : 19;
    char array[56];
};

extern "C" void* fn_68_D094(Object* self) {
    self->x = lbl_68_rodata_D4;
    self->y = lbl_68_rodata_D4;
    self->z = lbl_68_rodata_D4;
    self->flags3C = 0;
    self->a = lbl_68_data_2580;
    self->b = lbl_68_data_2580 + 0x48;
    self->flags4C = 0;
    __construct_array(self->array, fn_68_5E10, fn_68_5E20, 8, 7);
    return self;
}
