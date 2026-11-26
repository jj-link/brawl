#include <types.h>
#pragma force_active on

struct Pair { u32 x, y; };
struct Overlap { u32 w; Overlap& operator=(const Overlap& v) { w = v.w; ((u8*)this)[1] = ((const u8*)&v)[1]; ((u8*)this)[2] = ((const u8*)&v)[2]; ((u8*)this)[3] = ((const u8*)&v)[3]; return *this; } };
struct Data {
    u8 a[4]; u16 b; short c; u32 d, e;
    u64 f0; Pair f1, f2; u64 f3, f4; Pair f5, f6, f7; u8 g0,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10; u32 h[2]; u8 i0,i1,i2,i3,i4,i5,i6,i7; u8 im[12];
    u32 j; Overlap k; u8 l; u32 m[24]; u16 n[20]; u8 o[4]; u32 p; unsigned int : 32; u64 q0; u32 q[4]; u8 r[4]; u16 t;
};
struct Slot { char pad[0x70]; Data data; char pad2[0x218 - 0x70 - sizeof(Data)]; };
struct Obj { Slot slots[7]; char pad[0xfca - 7 * 0x218]; u8 flags; };

static inline bool fn_800D0E58_changed(u8* b, u8* a) {
    for (int i = 0; i < 3; ++i, a += 8, b += 8) {
        if (a[0x3a] != b[0x3a]) return true;
        if (a[0x3b] != b[0x3b]) return true;
    }
    return false;
}

extern "C" void fn_800D0E58(Obj* obj, s32 index, Data* src) {
    Slot* slot = &obj->slots[index];
    if (fn_800D0E58_changed((u8*)src, (u8*)&slot->data)) {
        obj->flags |= 2;
    }
    slot->data = *src;
    ((u8*)slot)[0x280] |= 0x40;
}
