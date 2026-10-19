#pragma force_active on
struct StGwObj {
    char pad0[0x28];
    void* m28;
    void* m2C;
    unsigned int m30;
};

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_63_9D70(int* p);
void fn_63_9D80(void* p, int size);
extern char lbl_63_data_3C40[];
void* fn_63_9AE0(StGwObj* self);
}

extern "C" void* fn_63_9AE0(StGwObj* self) {
    self->m28 = lbl_63_data_3C40;
    self->m2C = lbl_63_data_3C40 + 0x48;
    self->m30 &= 0x7FFFF;
    __construct_array((char*)self + 0x34, (void (*)(void*))fn_63_9D70, (void (*)(void*))fn_63_9D80, 8, 6);
    return self;
}
