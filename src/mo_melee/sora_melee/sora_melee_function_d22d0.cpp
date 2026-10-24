#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_data_15218[];
extern "C" const float lbl_27_rodata_F04;

struct Entry {
    s32 a;
    s32 b;
    u8 c;
    s32 d;
    f32 e;

    void reset() {
        a = -1;
        b = 0;
        c = 0;
        d = 0;
        e = lbl_27_rodata_F04;
    }
};

struct Header {
    void* p0;
    u8* p4;
    u32 flags : 8;
    u32 flags2 : 8;
    u32 remaining : 16;
    Entry first;
    Entry entries[7];
};

inline void resetEntries(u8* begin, u8* end) {
    u8* q = begin;
    do {
        ((Entry*)q)->a = -1;
        ((Entry*)q)->b = 0;
        ((Entry*)q)->c = 0;
        ((Entry*)q)->d = 0;
        ((Entry*)q)->e = lbl_27_rodata_F04;
        q += 20;
    } while (q < end);
}

extern "C" Header* fn_27_D22D0(Header* self) {
    self->p0 = lbl_27_data_15218;
    self->p4 = lbl_27_data_15218 + 0x48;
    self->flags = 0;
    self->flags2 = 0;
    resetEntries((u8*)&self->first, (u8*)(self->entries + 7));
    return self;
}
