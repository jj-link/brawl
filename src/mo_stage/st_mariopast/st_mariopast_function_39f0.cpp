#pragma force_active on
extern "C" {
extern char lbl_48_data_1430[];
void fn_48_3A5C(void*);
void fn_48_3A6C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct St {
    char pad0[0x28];
    void* m28;
    void* m2c;
    unsigned int m30;
};

extern "C" St* fn_48_39F0(St* self) {
    self->m28 = lbl_48_data_1430;
    self->m2c = lbl_48_data_1430 + 0x48;
    self->m30 &= 0x7FFFF;
    __construct_array((char*)self + 0x34, fn_48_3A5C, fn_48_3A6C, 8, 6);
    return self;
}
