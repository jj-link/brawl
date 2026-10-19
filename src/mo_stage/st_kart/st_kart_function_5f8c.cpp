#pragma force_active on

typedef unsigned int u32;

extern "C" char lbl_49_data_1ED0[];

struct Kart {
    char filler[0x28];
    char* field28;
    char* field2C;
    u32 field30;
    char arr[8 * 6];
};

extern "C" {
void fn_49_621C(void*);
void fn_49_622C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
}

extern "C" void* fn_49_5F8C(Kart* self) {
    self->field28 = lbl_49_data_1ED0;
    self->field2C = lbl_49_data_1ED0 + 0x48;
    self->field30 &= 0x7FFFF;
    __construct_array(&self->arr[0], fn_49_621C, fn_49_622C, 8, 6);
    return self;
}
