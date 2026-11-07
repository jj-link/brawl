#pragma force_active on
typedef unsigned char u8;
extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    char pad0[0x68];
    u8 states[4];
    char pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 player;
    char pad2[0x19E];
};

struct Parent { char pad[0x70]; Entry entries[5]; };

inline Entry* getLocalA(void* self) {
    u8 local = fn_800C851C();
    if (local == 0xFF) local = 4;
    return &((Parent*)self)->entries[local];
}

inline Entry* getLocal(void* self) {
    u8 local = fn_800C851C();
    if (local == 0xFF) local = 4;
    return (Entry*)((char*)self + local * 0x218 + 0x70);
}

inline Entry* getCur(void* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF) return 0;
    return &((Parent*)self)->entries[index];
}

inline Entry* getSelected(void* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF) return getLocal(self);
    Entry* entry = (Entry*)((unsigned long)self + index * 0x218 + 0x70);
    if (((((u8*)entry)[0x78] >> 7) & 1) == 0) entry = getLocal(self);
    return entry;
}

extern "C" u8 fn_800D4544(void* self) {
    Entry* e = getCur(self);
    if (e == 0) e = getLocalA(self);
    u8 player = e->player;
    int valid;
    if (player >= 4U) {
        valid = 0;
    } else {
        Entry* s = getSelected(self);
        valid = !(s->states[player] - 1);
    }
    if (!valid) return 0xFF;
    return e->player;
}
