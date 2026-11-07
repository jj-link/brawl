#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457158[];

struct Entry {
    char pad0[0x68];
    u8 states[4];
    char pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
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

    Entry* entry = (Entry*)((unsigned long)self + index * 0x218 + 0x70);
    if (!entry->active)
        return getLocal(self);
    return entry;
}

extern "C" u64 fn_800D9190(void* self) {
    char* base = lbl_80457158;
    u64 other = -1;
    u64 mask = -1;

    netReport__FPCce(base + 0x27F0);

    unsigned int i = 0;
    do {
        int valid;
        if ((u8)i >= 4U) {
            valid = 0;
        } else {
            Entry* entry = getSelected(self);
            valid = entry->states[(u8)i] == 1;
        }

        if (valid) {
            char* p = (char*)self + (u8)i * 0x218;
            u64 value = *(u64*)(p + 0x98);
            netReport__FPCce(base + 0x2808, (u8)i, value);
            mask &= value;
            other &= *(u64*)(p + 0xA0);
        }

        i++;
    } while (i < 4);

    netReport__FPCce(base + 0x2818, mask);

    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;

    char* p = (char*)self + local * 0x218;
    *(u32*)(p + 0x18C) = (u32)other;
    *(u32*)(p + 0x188) = (u32)(other >> 32);
    return mask;
}
