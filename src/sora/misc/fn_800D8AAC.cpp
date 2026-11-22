#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);
extern "C" void fn_8014FDE0(u8);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(s32, s32);
extern "C" u64 fn_803F1798(u64, u32);

extern "C" s32 lbl_805A03A8;
extern mtRand lbl_805A0420;

struct PlayerFlags {
    u8 active : 1;
    u8 other : 6;
    u8 bottom : 1;
};

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
    if (((((u8*)entry)[0x78] >> 7) & 1) == 0)
        return getLocal(self);
    return entry;
}

extern "C" void fn_800D8AAC(void* arg0) {
        int index;
    u8* selectedEntry;
    u64* maskOut;
    u8* slotOut;
    int count = 0;
    u8 allActive = 1;
    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;

    selectedEntry = (u8*)arg0 + local * 0x218;
    u64 masks[4];
    u8 slots[4];
    maskOut = masks;
    slotOut = slots;
    *(u32*)(selectedEntry + 0x198) = 0xFFFFFFFF;
    *(u32*)(selectedEntry + 0x19C) = 0xFFFFFFFF;

    for (u8 i = 0; i < 4; ++i) {
        masks[i] = 0;
        slots[i] = 0;

        int valid;
        if (i >= 4) {
            valid = 0;
        } else {
            Entry* entry = getSelected(arg0);
            valid = entry->states[i] == 1;
        }

        if (valid) {
            u8* player = (u8*)arg0 + i * 0x218;
            ++count;
            allActive &= ((PlayerFlags*)(player + 0xC6))->active;
            *maskOut++ = *(u64*)(player + 0x88);
            *slotOut++ = player[0x72];
            *(u32*)(selectedEntry + 0x198) &= *(u32*)(player + 0x90);
            *(u32*)(selectedEntry + 0x19C) &= *(u32*)(player + 0x94);
        }
    }

    fn_8014FDE0(allActive);
    u8 chosen = slots[(int)((float)count * lbl_805A0420.randf())];
    u64 combined = 0;
    for (int i = 0; i < 0x40; ++i) {
        index = (int)((float)count * lbl_805A0420.randf());
        u64 bits = fn_803F1798(1ULL, i);
        combined |= bits & masks[index];
    }

    selectedEntry[0x17F] = chosen;
    *(u64*)(selectedEntry + 0x190) = combined;

    u8 own = fn_800C851C();
    if (own == 0xFF)
        own = 4;
    u8* entry = (u8*)arg0 + own * 0x218;
    ((PlayerFlags*)(entry + 0xC6))->bottom = 0;
    fn_800D0AE0(arg0, entry);
    fn_80145B98(lbl_805A03A8, 0xFE);
}
