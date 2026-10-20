#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad0[4];
    u16 m_id;
    f32 m_f0;
    f32 m_f1;
    u8 m_flag;
};

struct Out {
    u16 m_id;
    f32 m_f0;
    f32 m_f1;
    u8 m_flag;
};

struct Owner {
    u8 pad[0x48];
    u8* m_table;
};

extern "C" s32 fn_27_22AF0C(Owner* self, u8* table, u32 key, u32* idx);

extern "C" {
s32 fn_27_22B3B8(Owner* self, u32 key, Out* out) {
    u32 idx;
    if (fn_27_22AF0C(self, self->m_table, key, &idx) != 0) {
        Entry* e = (Entry*)(self->m_table + idx * 0x14);
        out->m_id = e->m_id;
        out->m_f0 = e->m_f0;
        out->m_f1 = e->m_f1;
        out->m_flag = e->m_flag;
        return 1;
    }
    return 0;
}
}
