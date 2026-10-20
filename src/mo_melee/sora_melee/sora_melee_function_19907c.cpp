#pragma force_active on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_A6948(void*);
void fn_27_A6978(void*);
extern char lbl_27_data_3A158[];
}

struct Obj {
    void* m0;
    void* m4;
    unsigned int m8;
};

extern "C" {
void* fn_27_19907C(Obj* self) {
    self->m0 = lbl_27_data_3A158;
    self->m4 = lbl_27_data_3A158 + 0x48;
    self->m8 = self->m8 & 0x3FFFFF;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_A6948, (void (*)(void*))fn_27_A6978, 0x24, 3);
    return self;
}
}
