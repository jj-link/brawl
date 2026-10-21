#pragma force_active on

extern "C" {
extern const float lbl_57_rodata_274;
extern char lbl_57_data_2268[];

void fn_57_A778(void*);
void* fn_57_A788(void*, int);
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

extern "C" void* fn_57_A654(Object* self) {
    self->x = lbl_57_rodata_274;
    self->y = lbl_57_rodata_274;
    self->z = lbl_57_rodata_274;
    self->flags = 0;
    self->a = lbl_57_data_2268;
    self->b = lbl_57_data_2268 + 0x48;
    self->flags4c = 0;
    __construct_array(self->items, fn_57_A778,
                      (void (*)(void*))fn_57_A788, 8, 7);
    return self;
}
