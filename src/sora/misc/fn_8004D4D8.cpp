#include <types.h>
#pragma force_active on
extern "C" void fn_800557A8();
extern "C" void* memset(void*, int, unsigned long);
extern "C" void* memcpy(void*, const void*, unsigned long);
extern u8 lbl_80406938[];
struct Entry {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x50];
    u32 unk54[35];
    u16 unkE0[6];
    u8 unkEC;
    u8 padED;
    u16 unkEE;
    u32 unkF0;
    u8 unkF4[0x30];
};
struct Self {
    u8 pad0[0x24];
    u8* unk24;
    Entry* unk28;
};
inline void init(Self* self, int idx, s32& off2) {
    u32 off;
    Entry* f;
    Entry* e;
    fn_800557A8();
    off = (u8)idx * sizeof(Entry);
    f = (Entry*)((u8*)self->unk28 + off);
    off2 = idx * 0x124;
    e = (Entry*)((u8*)self->unk28 + off2);
    f->unk0 = 0;
    f->unk2 = 0;
    memset(f->unk4, 0, 0x50);
    for (int j = 0; j < 35; j++) f->unk54[j] = 0;
    f->unkEE = 0;
    memcpy(((Entry*)((u8*)self->unk28 + off))->unkF4, lbl_80406938, 0x2D);
    e->unkE0[0] = 0;
    e->unkEC = 1;
}
extern "C" void fn_8004D4D8(Self* self, s32 arg1, u16* arg2, s32 arg3, s32 arg4) {
    s32 off2;
    init(self, arg1, off2);
    Entry* e3 = (Entry*)((u8*)self->unk28 + off2);
    u8* dst = (u8*)e3;
    s32 i = 0;
    u16 v;
    while (i < 5 && (v = *arg2) != 0) {
        *(u16*)(dst + 0xE0) = v;
        dst += 2;
        i++;
        arg2++;
    }
    e3->unkE0[i] = 0;
    e3->unkF0 = arg4;
    e3->unkEC = ((self->unk24 + arg3)[0x820] != 0);
}