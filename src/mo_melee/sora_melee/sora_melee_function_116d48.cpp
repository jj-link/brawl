#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Vec3f {
    float x, y, z;
};

class Fighter {
public:
    void warp(Vec3f*, float, u32);
};

struct FighterSlot {
    Fighter* fighter;
    u32 unknown;
};

struct ftEntry {
    u8 pad00[0xA];
    u8 index;
    u8 pad0B[3];
    u8 flags;
    u8 state;
    u8 pad10[0x24];
    FighterSlot fighters[2];
};

extern "C" void fn_27_116D48(ftEntry* entry, Vec3f* pos, float lr, u32 flags) {
    if (entry->state == 6) {
        entry->fighters[entry->index].fighter->warp(pos, lr, flags);
        if (entry->flags & 2) {
            entry->fighters[1].fighter->warp(pos, lr, flags);
        }
    }
}
