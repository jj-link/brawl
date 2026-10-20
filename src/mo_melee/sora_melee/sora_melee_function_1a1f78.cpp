#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_3E0E0[];
void fn_27_D2A0C(void* p);
void fn_27_AB510(void* p, s32 n);
void __construct_array(void* p, void (*ctor)(void*), void (*dtor)(void*), unsigned long size, int count);
}

struct fnS27_1A1F78 {
    void* unk0;
    void* unk4;
    u32 unk8;
};

extern "C" void* fn_27_1A1F78(fnS27_1A1F78* self) {
    self->unk0 = lbl_27_data_3E0E0;
    self->unk4 = lbl_27_data_3E0E0 + 0x48;
    self->unk8 = (u16)self->unk8;
    __construct_array((char*)self + 0xc, (void (*)(void*))fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 8);
    return self;
}
