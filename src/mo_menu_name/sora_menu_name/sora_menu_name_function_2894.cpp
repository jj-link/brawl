#pragma force_active on

typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

struct GameGlobal;

struct Entry {
    u8 pad[2];
    s16 idx;
};

struct Menu {
    u8 pad0[0x1F0];
    Entry entries[122];
    u16 unk3D8;
};

extern void* g_GameGlobal;
extern "C" s32 fn_8004D148(void*);
extern "C" s32 fn_16_2A48(const Entry* a, const Entry* b);
extern "C" void fn_803F8ACC(void*, unsigned int, unsigned int, s32 (*)(const Entry*, const Entry*));

extern "C" void fn_16_2894(Menu* self) {
    Entry* p = self->entries;
    p += 1;
    self->entries[0].idx = -1;
    self->unk3D8 = 1;
    s32 n = fn_8004D148(g_GameGlobal);
    for (s32 i = 0; i < n; i++, p++) {
        p->idx = i;
        self->unk3D8++;
    }
    if (self->unk3D8 > 5) {
        p->idx = -2;
        self->unk3D8++;
    }
    if (n > 1) {
        fn_803F8ACC(&self->entries[0], self->unk3D8, 4, fn_16_2A48);
    }
}
