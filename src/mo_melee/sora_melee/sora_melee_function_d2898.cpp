#include <types.h>
#pragma force_active on

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, s32);
}

extern u8 lbl_27_data_1A4E8[];

struct ArrayElem {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct Thing {
    void* m_0;
    void* m_4;
    u32 m_8;
    ArrayElem m_arr[3];
};

extern "C" Thing* fn_27_D2898(Thing* self) {
    self->m_0 = &lbl_27_data_1A4E8;
    self->m_4 = (char*)&lbl_27_data_1A4E8 + 0x48;
    self->m_8 &= 0x003FFFFF;
    __construct_array(&self->m_arr, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 3);
    return self;
}
