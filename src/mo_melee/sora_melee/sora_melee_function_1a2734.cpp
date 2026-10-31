#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" char lbl_27_data_3D420[0x90];

struct Pair {
    u32 a, b;

    void reset() {
        a = 0;
        b |= 0xFFFF0000;
        b |= 0xFFFF;
    }
};

struct S {
    void* p0;
    void* p4;
    u32 hi : 13;
    u32 lo : 19;
    Pair entries[5];
};

inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        ((Pair*)p)->reset();
        p += 8;
    } while (p < end);
}

extern "C" S* fn_27_1A2734(S* self) {
    self->p0 = lbl_27_data_3D420;
    self->p4 = lbl_27_data_3D420 + 0x48;
    self->hi = 0;
    resetEntries((u8*)self->entries, (u8*)(self->entries + 5));
    return self;
}
