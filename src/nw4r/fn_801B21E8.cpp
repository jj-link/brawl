#include <types.h>
#pragma force_active on

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void*, u32);
extern "C" void fn_801AE08C(void*, void*, void*);
extern "C" void fn_80197AFC(s8*, u32*, void*);
extern "C" void fn_80197A40(u32*, void*);
extern "C" void fn_801AE2E8(void*, void*, void*);
extern "C" void fn_801AE31C(void*, void*, void*);
extern "C" void fn_801B17E0(void*, void*, void*);
extern "C" void fn_801AB3C4(void*, u32, void*, void*);
extern "C" void fn_801AF9F4(void*);
extern "C" u32 fn_801AFAEC(void*);
extern "C" u32 fn_801AFB10(void*);
extern "C" u32 fn_801AFB44(void*);
extern "C" void fn_801A64B0(u32*, u32, u32, u32, u32, u32, void*, u32);
extern "C" void fn_801B6AE8(u32*, void*, u32, u32, u32);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(u32, void*, void*, void*);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(u32, void*, void*, void*);
    virtual void slot5(u32, void*, void*, void*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
};

class Class_804663D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_801B21E8();
    virtual void fn_801B33D8();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050(void*);

    u8 pad0[0xcc - 4];
    u32 mask;          // 0xcc
    u8 pad1[0xd4 - 0xd0];
    Object_vptr_0* h;  // 0xd4
    u8 b;              // 0xd8
    u8 pad2[1];
    u16 hw;            // 0xda
    u8 pad3[0xe8 - 0xdc];
    u32 mdl;           // 0xe8
    u8 pad4[0x110 - 0xec];
    u32 x110;
    u32 x114;
    u32 x118;
    u8 pad5[0x128 - 0x11c];
    void* h2;          // 0x128
    u8 pad6[0x138 - 0x12c];
    Object_vptr_0* sub; // 0x138
    u32 flag;          // 0x13c
    u8 pad7[0x144 - 0x140];
    u8 x144[4];        // 0x144
    u8* flags;         // 0x148
    u8 pad8[0x178 - 0x14c];
    u32 x178;
    u32 x17c;
    u32 x180;
};

extern "C" void fn_801B21E8(Class_804663D0* self, u32 arg1, void* arg2, u32* arg3) {
    s32 masked;
    if (arg1 < 9U && ((1U << (arg1 - 1)) & self->mask)) {
        masked = 1;
    } else {
        masked = 0;
    }
    if (masked != 0)
        return;

    switch (arg1) {
    case 0x5:
        fn_801AE2E8(self, arg2, arg3);
        break;
    case 0x1: {
        u32 sp1C;
        u32 sp18;
        u32 sp14;
        fn_801AE08C(self, arg2, arg3);
        if (!(self->flag & 2) && (self->flag & 1)) {
            sp1C = self->mdl;
            u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sp1C);
            if (self->flags) {
                u32 i = 0;
                if (count) {
                    while (i < count) {
                        void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp1C, i);
                        u32 nv;
                        if (node)
                            nv = (*(u32*)((u8*)node + 0x14) >> 8) & 1;
                        else
                            nv = 0;
                        if (nv)
                            self->flags[i] = 1;
                        else
                            self->flags[i] = 0;
                        i++;
                    }
                }
            }
            self->flag &= ~1;
        }
        void* h2v = self->h2;
        if (h2v) {
            if (self->flags) {
                sp14 = self->mdl;
                fn_80197AFC((s8*)self->flags, &sp14, h2v);
                self->flag |= 1;
            } else {
                sp18 = self->mdl;
                fn_80197A40(&sp18, h2v);
            }
        }
        if (self->h && (self->hw & 1) && (self->b & 4))
            self->h->slot1(4, self, arg2, arg3);
        break;
    }
    case 0x2:
        fn_801B17E0(self, arg2, arg3);
        break;
    case 0x4:
        fn_801AE31C(self, arg2, arg3);
        break;
    case 0x6: {
        u32 v;
        if (self->h && (self->hw & 0x10) && (self->b & 1))
            self->h->slot4(1, self, arg2, arg3);
        if (arg3)
            v = *arg3;
        else
            v = self->x118;
        u32 a = self->x110;
        u32 sp10 = self->mdl;
        fn_801A64B0(&sp10, fn_801AFAEC(self), fn_801AFB10(self), fn_801AFB44(self), a, 0, self->x144, v);
        if (self->h && (self->hw & 0x10) && (self->b & 4))
            self->h->slot4(4, self, arg2, arg3);
        break;
    }
    case 0x7: {
        u32 v;
        if (self->h && (self->hw & 0x20) && (self->b & 1))
            self->h->slot5(1, self, arg2, arg3);
        if (arg3)
            v = *arg3;
        else
            v = self->x118;
        u32 a = self->x114;
        u32 spC = self->mdl;
        fn_801A64B0(&spC, fn_801AFAEC(self), fn_801AFB10(self), fn_801AFB44(self), 0, a, self->x144, v);
        if (self->h && (self->hw & 0x20) && (self->b & 4))
            self->h->slot5(4, self, arg2, arg3);
        break;
    }
    case 0x8:
        fn_801AF9F4(self);
        if (self->sub != 0)
            self->sub->slot7();
        break;
    case 0x10001:
        self->fn_801B3050(arg3);
        break;
    case 0x3: {
        Object_vptr_0* s = self->sub;
        if (s) {
            u32 sp8 = self->mdl;
            fn_801B6AE8(&sp8, s, self->x178, self->x17c, self->x180);
        }
        break;
    }
    default:
        fn_801AB3C4(self, arg1, arg2, arg3);
        break;
    }
}
