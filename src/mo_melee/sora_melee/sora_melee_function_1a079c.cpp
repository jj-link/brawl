#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#pragma force_active on
extern "C" char lbl_27_data_3FB18[];
extern "C" const f32 lbl_27_rodata_2708;
struct Layout {
    void* vt0;
    void* vt4;
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;
    u32 m_isFull : 1;
    acCmdInterpreterStackData first;
    acCmdInterpreterStackData entries[9];
};
inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        acCmdInterpreterStackData* q = (acCmdInterpreterStackData*)p;
        q->kind = acCmdInterpreterStackData::Invalid;
        q->intData = 0;
        q->boolData = false;
        q->addressData = 0;
        q->floatData = lbl_27_rodata_2708;
        p += 20;
    } while (p < end);
}
extern "C" Layout* fn_27_1A079C(Layout* self) {
    self->vt0 = lbl_27_data_3FB18;
    self->vt4 = lbl_27_data_3FB18 + 0x48;
    self->m_topIndex = 0;
    self->m_lastIndex = 0;
    self->m_size = 0;
    self->m_isFull = 0;
    resetEntries((u8*)&self->first, (u8*)(self->entries + 9));
    return self;
}