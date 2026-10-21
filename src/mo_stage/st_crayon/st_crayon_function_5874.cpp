#pragma force_active on

extern "C" {
extern const float lbl_56_rodata_98;
extern char lbl_56_data_21A8[];

void fn_56_5A00(void*);
void* fn_56_5A10(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct Object {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    unsigned long : 27;
    unsigned long flags : 5;
    unsigned long pad40;
    char* a;
    char* b;
    unsigned long flags4c : 13;
    unsigned long : 19;
    char items[7][8];
};

extern "C" void* fn_56_5874(Object* self) {
    self->x = lbl_56_rodata_98;
    self->y = lbl_56_rodata_98;
    self->z = lbl_56_rodata_98;
    self->flags = 0;
    self->a = lbl_56_data_21A8;
    self->b = lbl_56_data_21A8 + 0x48;
    self->flags4c = 0;
    __construct_array(self->items, fn_56_5A00,
                      (void (*)(void*))fn_56_5A10, 8, 7);
    return self;
}
