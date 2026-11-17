#pragma force_active on
#include <types.h>

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    u8 pad0[0x68];
    u8 states[4];
    u8 pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 player;
    u8 pad2[0x218 - 0x7A];
};

struct Parent {
    u8 pad[0x70];
    Entry entries[5];
};

inline u8 localIdx() {
    u8 l = fn_800C851C();
    if (l == 0xFF)
        l = 4;
    return l;
}

extern "C" s32 fn_800D7C0C(void* self, s32 slot, s32 flag) {
    Parent* parent = (Parent*)self;
    Entry* e;
    u8* q;
    s32 cond = (*((u8*)self + 0xFCA) >> 5) & 1;
    u8 player;

    if (cond == 0) {
        u8 idx = fn_800C8548();
        if (idx == 0xFF)
            e = 0;
        else
            e = &parent->entries[idx];

        if (e == 0)
            e = &parent->entries[localIdx()];

        player = e->player;
        s32 v;
        if (player >= 4)
            v = 0;
        else {
            u8 s = fn_800C8548();
            Entry* t;
            if (s == 0xFF)
                t = &parent->entries[localIdx()];
            else {
                t = &parent->entries[s];
                if (!t->active)
                    t = &parent->entries[localIdx()];
            }
            v = (t->states[player] - 1) == 0;
        }

        u8 pick = v ? e->player : 0xFF;
        cond = (pick == localIdx());
    }

    if (!cond)
        return 0;

    int off;
    u8* p;
    if (flag != 0) {
        off = slot * 8;
        p = (u8*)self + off;
        q = p + 0x4C;
        if (p[0x4C] != 0xFF)
            return 0;
    } else {
        u8 local = localIdx();
        off = slot * 8;
        p = (u8*)self + off;
        q = p + 0x4C;
        if (p[0x4C] != local || !((p[0x51] >> 7) & 1))
            return 0;
    }

    ((u8*)self + off)[0x4C] = 0xFF;
    ((u8*)self + off)[0x4D] = 0;
    *(u32*)((u32)self + off + 0x50) &= 0xFFFFFF;
    ((u8*)self + off)[0x4E] = 0;
    ((u8*)self + off)[0x4F] = 0;
    ((u8*)self + off)[0x51] =
        (u8)((((u8*)self + off)[0x51] & ~0x80) | ((flag << 7) & 0x80));

    if (flag != 0)
        *q = localIdx();

    return 1;
}
