#include <types.h>
#include <ac/ac_cmd_interpreter.h>

#pragma force_active on

extern "C" u8 lbl_27_data_1AC38[];
extern "C" const f32 lbl_27_rodata_F04;

struct Layout {
    void* vt0;
    void* vt4;
    s32 m_topIndex : 6;
    s32 m_lastIndex : 6;
    s32 m_size : 6;
    u32 m_isFull : 1;
    acCmdInterpreterStackData first;
    acCmdInterpreterStackData entries[15];
};

inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        acCmdInterpreterStackData* q = (acCmdInterpreterStackData*)p;
        q->kind = acCmdInterpreterStackData::Invalid;
        q->intData = 0;
        q->boolData = false;
        q->addressData = 0;
        q->floatData = lbl_27_rodata_F04;
        p += 20;
    } while (p < end);
}

extern "C" Layout* fn_27_D19E8(Layout* self) {
    self->vt0 = lbl_27_data_1AC38;
    self->vt4 = lbl_27_data_1AC38 + 0x48;
    self->m_topIndex = 0;
    self->m_lastIndex = 0;
    self->m_size = 0;
    self->m_isFull = 0;
    resetEntries((u8*)&self->first, (u8*)(self->entries + 15));
    return self;
}
