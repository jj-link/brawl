#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void fn_800557A8();
extern "C" u32 fn_80050668();
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
    u8 pad[0x24];
    u8* unk24;
    Entry* unk28;
};

extern "C" void fn_8004D334(Owner* self, s32 idx, u16* src, s32 arg3) {
    fn_800557A8();
    u32 t = fn_80050668();
    fn_800557A8();

    Entry* e2;
    Entry* f;
    s32 off24 = (u8)idx * 0x124;
    f = (Entry*)((u8*)self->unk28 + off24);
    idx = idx * 0x124;
    e2 = (Entry*)((u8*)self->unk28 + idx);

    f->unk0 = 0;
    f->unk2 = 0;
    memset(f->unk4, 0, 0x50);
    for (s32 j = 0; j < 35; j++) f->unk54[j] = 0;
    f->unkEE = 0;
    memcpy(((Entry*)((u8*)self->unk28 + off24))->unkF4, lbl_80406938, 0x2D);
    e2->unkE0 = 0;
    e2->unkEC = 1;

    Entry* e3 = (Entry*)((u8*)self->unk28 + idx);
    s32 n = 0;
    u8* d = (u8*)self->unk28 + idx;
    u16* s = src;
    while (n < 5 && *s != 0) {
        *(u16*)(d + 0xE0) = *s;
        d += 2;
        n++;
        s++;
    }
    *(u16*)((u8*)e3 + n * 2 + 0xE0) = 0;
    *(u32*)((u8*)e3 + 0xF0) = t;
    e3->unkEC = (self->unk24[arg3 + 0x820] != 0);
}
