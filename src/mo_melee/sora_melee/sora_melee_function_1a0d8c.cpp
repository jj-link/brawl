#include <types.h>
#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

extern "C" u8 lbl_27_data_374E8[];
extern "C" const f32 lbl_27_rodata_2708;

struct Obj {
    u8* vt0;
    u8* vt1;
    s32 top : 3;
    s32 last : 3;
    s32 size : 3;
    u32 full : 1;
    u32 remaining : 22;
    acCmdInterpreterStackData m_last;
    acCmdInterpreterStackData m_elements[2];
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

extern "C" Obj* fn_27_1A0D8C(Obj* self) {
    self->vt0 = lbl_27_data_374E8;
    self->vt1 = lbl_27_data_374E8 + 0x48;
    self->top = 0;
    self->last = 0;
    self->size = 0;
    self->full = 0;
    resetEntries((u8*)&self->m_last, (u8*)(self->m_elements + 2));
    return self;
}
