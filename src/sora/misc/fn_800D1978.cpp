#pragma force_active on
typedef unsigned char u8;
extern "C" int fn_8014592C(int);
extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern int lbl_805A03A8;
struct Entry { char pad0[0x68]; u8 states[4]; char pad1[0xC]; u8 active : 1; u8 flags : 7; char pad2[0x19F]; };
inline Entry* getLocal(void* self) { u8 local = fn_800C851C(); if (local == 0xFF) local = 4; return (Entry*)((char*)self + local * 0x218 + 0x70); }
inline Entry* getSelected(void* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF) return getLocal(self);
    Entry* entry = (Entry*)((unsigned long)self + index * 0x218 + 0x70);
    if (((((u8*)entry)[0x78] >> 7) & 1) == 0) entry = getLocal(self);
    return entry;
}
extern "C" int fn_800D1978(void* self) {
    if (!fn_8014592C(lbl_805A03A8)) return 0;
    for (unsigned int i = 0; i < 4; i++) {
        int valid; if ((u8)i >= 4U) valid = 0; else { Entry* entry = getSelected(self); valid = !(entry->states[(u8)i] - 1); }
        if (valid) { u8* p = (u8*)self + (u8)i * 0x218; if (!((p[0xC6] >> 6) & 1)) return 0; }
    }
    return 1;
}