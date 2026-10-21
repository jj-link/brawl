#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    char pad0[0x68];
    u8 states[4];
    char pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    char pad2[0x198];
    s8 result;
    char pad3[6];
};

struct Parent {
    char pad[0x70];
    Entry entries[5];
};

inline Entry* getLocal(void* self) {
    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;
    return (Entry*)((char*)self + local * 0x218 + 0x70);
}

inline Entry* getSelected(void* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF)
        return getLocal(self);

    Entry* entry = &((Parent*)self)->entries[index];
    if (!entry->active)
        return getLocal(self);

    return entry;
}

extern "C" int fn_800D27A0(void* self, int slot) {
    u8 player = *((u8*)self + slot * 8 + 0x4C);
    bool valid;

    if (player >= 4U) {
        valid = false;
    } else {
        Entry* entry = getSelected(self);
        valid = entry->states[player] == 1;
    }

    if (!valid)
        return -1;

    return ((Parent*)self)->entries[player].result;
}
