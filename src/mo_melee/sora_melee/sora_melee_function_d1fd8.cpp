#include <types.h>
#include <so/so_array.h>
#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

extern "C" u8 lbl_27_data_1AA48[];
extern "C" const f32 lbl_27_rodata_F04;

struct Obj {
    void* p0;
    u8* p4;
    s32 top : 4;
    s32 last : 4;
    s32 size : 4;
    u32 full : 1;
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
        q->floatData = lbl_27_rodata_F04;
        p += 20;
    } while (p < end);
}

extern "C" Obj* fn_27_D1FD8(Obj* self) {
    self->p0 = lbl_27_data_1AA48;
    self->p4 = lbl_27_data_1AA48 + 0x48;
    self->top = 0;
    self->last = 0;
    self->size = 0;
    self->full = 0;
    resetEntries((u8*)&self->first, (u8*)(self->entries + 6));
    return self;
}
