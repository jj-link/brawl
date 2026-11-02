#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void fn_800557A8();
extern u8 lbl_80406938[];

struct Entry {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x50];
    u32 unk54[35];
    u16 unkE0;
    u8 padE2[0xEC - 0xE2];
    u8 unkEC;
    u8 padED;
    u16 unkEE;
    u8 padF0[4];
    u8 unkF4[0x124 - 0xF4];
};

struct Owner {
    u8 pad[0x28];
    Entry* unk28;
};

extern "C" void fn_8004D20C(Owner* self, int idx) {
    Entry* e;
    Entry* f;
    u32 off;
    fn_800557A8();
    off = (u8)idx * sizeof(Entry);
    f = (Entry*)((u8*)self->unk28 + off);
    e = &self->unk28[idx];
    f->unk0 = 0;
    f->unk2 = 0;
    memset(f->unk4, 0, 0x50);
    for (int j = 0; j < 35; j++) f->unk54[j] = 0;
    f->unkEE = 0;
    memcpy(((Entry*)((u8*)self->unk28 + off))->unkF4, lbl_80406938, 0x2D);
    e->unkE0 = 0;
    e->unkEC = 1;
}
