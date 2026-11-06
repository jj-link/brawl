#pragma force_active on

typedef unsigned char u8;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" int fn_8014592C(int);
extern int lbl_805A03A8;

struct Entry {
    char pad0[0x68];
    u8 states[4];
    char pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
};

inline Entry* getLocal(void* self) {
    u8 local = fn_800C851C();
    if (local == 0xFF) local = 4;
    return (Entry*)((char*)self + local * 0x218 + 0x70);
}

inline Entry* getSelected(void* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF) return getLocal(self);
    Entry* entry = (Entry*)((unsigned long)self + index * 0x218 + 0x70);
    if (!entry->active) return getLocal(self);
    return entry;
}

extern "C" int fn_800D1D10(void* self, int flags) {
    if (!fn_8014592C(lbl_805A03A8))
        return 0;
    u8 mask = 0xff;
    unsigned int i = 0;
    do {
        int valid;
        if ((u8)i >= 4U)
            valid = 0;
        else {
            Entry* entry = getSelected(self);
            valid = entry->states[(u8)i] == 1;
        }
        u8 v;
        if (valid)
            v = ((u8*)self + (u8)i * 0x218)[0xCA];
        else
            v = 0xff;
        i++;
        mask &= v;
    } while (i < 4);
    return (flags & mask) == flags;
}