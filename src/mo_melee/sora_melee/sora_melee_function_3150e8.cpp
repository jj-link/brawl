#pragma force_active on
#pragma exceptions off

extern "C" {
void fn_27_711E4(void*, short, void*);
void fn_27_C93EC(void*);
void fn_27_C940C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern unsigned char lbl_27_data_1A248[];
extern unsigned char lbl_27_data_84D70[];
}

struct Obj {
    unsigned char pad[0x24];
    unsigned char* p24;
    unsigned char b28;
    unsigned char pad_29[3];
    unsigned char* p2c;
    unsigned char* p30;
    unsigned char* p34;
    unsigned char* p38;
    unsigned int f3c;
    unsigned char arr[0x70];
    unsigned char bB0;
};

extern "C" Obj* fn_27_3150E8(Obj* self, short id) {
    fn_27_711E4(self, id, &self->p24);
    unsigned char* base = lbl_27_data_84D70;
    self->b28 = 0;
    self->p24 = base;
    self->p2c = base + 0x34;
    self->p30 = base + 0x40;
    self->p34 = lbl_27_data_1A248;
    self->p38 = lbl_27_data_1A248 + 0x48;
    self->f3c &= 0x7FFFF;
    __construct_array(self->arr, fn_27_C93EC, fn_27_C940C, 0x10, 7);
    self->bB0 = 0;
    return self;
}
