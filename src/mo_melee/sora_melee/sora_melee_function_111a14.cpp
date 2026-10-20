#include <types.h>
#pragma force_active on

struct Sub27 {
    u8 pad0[0x44];
    u32 m_44;
};

extern "C" Sub27* fn_27_14D600();

struct Data27 {
    u8 pad0[0x38];
    u32 m_arr[7];
    u32 m_54;
};

struct Obj27 {
    Data27* m_data;
    u8 pad4[0x6];
    u8 m_flag;
};

extern "C" {
void fn_27_111A14(Obj27* self, u32 idx, u32 val) {
    if (self->m_flag == 1) {
        self->m_data->m_arr[idx] = val;
    }
    Sub27* s = fn_27_14D600();
    self->m_data->m_54 = s->m_44;
}
}
