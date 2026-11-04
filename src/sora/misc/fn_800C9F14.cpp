#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    u8 pad0[0x68];
    u8 states[4];
    u8 pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 unk79;
    u8 pad2[0xC5 - 0x7A];
    u8 unkC5;
    u8 pad3[0x218 - 0xC6];
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

inline Entry* getLocal(void* self) {
    return &((Parent*)self)->entries[localIdx()];
}

inline Entry* getSelectedA(u8* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF)
        return getLocal(self);
    Entry* entry = &((Parent*)self)->entries[index];
    if (!entry->active)
        return getLocal(self);
    return entry;
}

inline u8* getSelected(u8* self) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF)
        return (u8*)getLocal(self);
    u8* p = self + idx * 0x218;
    u8* entry = p + 0x70;
    if (!((p[0xE8] >> 7) & 1))
        return (u8*)getLocal(self);
    return entry;
}

extern "C" u8 fn_800C9F14(void* self, int slot) {
    Entry* e;
    u8 r30;
    int off = slot * 8;
    u8 player = ((u8*)self + off)[0x4C];
    int sub = ((u8*)self + off)[0x4D];
    u8* base = (u8*)self;
    int cond = (base[0xFCA] >> 5) & 1;

    if (cond == 0) {
        u8 idx = fn_800C8548();
        if (idx == 0xFF)
            e = 0;
        else
            e = &((Parent*)base)->entries[idx];
        if (e == 0)
            e = getLocal(base);
        r30 = e->unk79;
        int v;
        if (r30 >= 4) {
            v = 0;
        } else {
            Entry* t = getSelectedA(base);
            v = (t->states[r30] == 1);
        }
        u8 pick = v ? e->unk79 : 0xFF;
        cond = (pick == localIdx());
    }

    if (cond != 0 && (((base + off)[0x51] >> 7) & 1))
        return 0;
    if (player == 4)
        return 0;
    if (player > 4)
        return 0;

    u8* g = getSelected(base);
    int v2;
    if ((g + player)[0x68] != 1) {
        v2 = 0;
    } else {
        s32 w = *(s32*)(g + 0x84 + player * 0x18 + sub * 8);
        v2 = ((w >> 24) == 1);
    }
    if (!v2)
        return 0;
    return (base + player * 0x218)[0xC5];
}
