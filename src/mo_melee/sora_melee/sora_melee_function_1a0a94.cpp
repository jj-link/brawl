#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_375E0[];
extern "C" const f32 lbl_27_rodata_2708;

struct Entry {
    s32 kind;
    s32 intData;
    u8 boolData;
    s32 addressData;
    f32 floatData;

    void reset(s32 k = -1, s32 i = 0, u8 b = 0, s32 a = 0) {
        kind = k;
        intData = i;
        boolData = b;
        addressData = a;
        floatData = lbl_27_rodata_2708;
    }
};

struct Obj {
    u8* vt0;
    u8* vt1;
    s32 top : 3;
    s32 last : 3;
    s32 size : 3;
    u32 full : 1;
    u32 remaining : 22;
    Entry m_last;
    Entry m_elements[1];
};

inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        ((Entry*)p)->reset();
        p += 20;
    } while (p < end);
}

extern "C" Obj* fn_27_1A0A94(Obj* self) {
    self->vt0 = lbl_27_data_375E0;
    self->vt1 = lbl_27_data_375E0 + 0x48;
    self->top = 0;
    self->last = 0;
    self->size = 0;
    self->full = 0;
    resetEntries((u8*)&self->m_last, (u8*)(self->m_elements + 1));
    return self;
}
