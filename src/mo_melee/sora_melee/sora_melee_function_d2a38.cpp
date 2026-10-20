#pragma force_active on
typedef unsigned int u32;

struct D2A38 {
    void* dataBegin;
    void* dataEnd;
    u32 flags;
    unsigned char elements[64];
};

extern "C" void fn_27_D2A0C(void*);
extern "C" void* fn_27_AB510(void*, int);
extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern unsigned char lbl_27_data_1A3D8[];

extern "C" D2A38* fn_27_D2A38(D2A38* self) {
    self->dataBegin = lbl_27_data_1A3D8;
    self->dataEnd = lbl_27_data_1A3D8 + 0x48;
    self->flags &= 0x7FFFF;

    __construct_array(self->elements, fn_27_D2A0C,
                      reinterpret_cast<void (*)(void*)>(fn_27_AB510), 16, 4);
    return self;
}
