#pragma force_active on
struct StGwObj {
    char pad0[0x28];
    float m28;
    float m2C;
    float m30;
    char pad34[8];
    unsigned int m3C : 27;
    unsigned int flags3C : 5;
    unsigned int m40;
    void* m44;
    void* m48;
    unsigned int m4C;
};

extern "C" {
extern const float lbl_63_rodata_B8;
extern char lbl_63_data_37F0[];

void fn_63_9D70(int*);
void fn_63_9D80(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

extern "C" void* fn_63_9C4C(StGwObj* self) {
    self->m28 = lbl_63_rodata_B8;
    self->m2C = lbl_63_rodata_B8;
    self->m30 = lbl_63_rodata_B8;
    self->flags3C = 0;
    self->m44 = lbl_63_data_37F0;
    self->m48 = lbl_63_data_37F0 + 0x48;
    self->m4C &= 0x7FFFF;
    __construct_array((char*)self + 0x50,
                      (void (*)(void*))fn_63_9D70,
                      (void (*)(void*))fn_63_9D80, 8, 7);
    return self;
}
