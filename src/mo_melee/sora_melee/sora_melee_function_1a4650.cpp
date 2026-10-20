#include <types.h>
#pragma force_active on

extern "C" extern u8 lbl_27_data_35A00[];

struct fn_27_1A4650_obj {
    u8* m_ptr;
    u8* m_end;
    u32 m_flag;
};

extern "C" void fn_27_1A4650(fn_27_1A4650_obj* self) {
    u8* base = lbl_27_data_35A00;
    u32 flag = self->m_flag;
    self->m_ptr = base;
    self->m_end = base + 0x48;
    self->m_flag = flag & 1;
}
