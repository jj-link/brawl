#include <types.h>
#pragma force_active on

static inline u32 rnd32(u32 n) {
    return (n + 0x1f) & ~0x1fU;
}

class Class_80466388;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(u32, void*, void*, void*);
    virtual void slot2(u32, void*, void*, void*);
    virtual void slot3(u32, void*, void*, void*);
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

class Arg3Obj {
public:
    virtual void slot0();
    virtual void slot1(void*, u32, u32);
};

class Class_80466388 {
public:
    virtual void fn_801AFEB4();
    virtual void fn_801AE668();
    virtual void fn_801AFD90();
    virtual void fn_8007FDF4();
    virtual void fn_801AFF1C();
    virtual void fn_801AB1C4();
    virtual void fn_801AEEF8();
    virtual void fn_801AEF40();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801AF0C4();
    virtual void fn_801AF6C0(void*);

    u8 pad0[0xcc - 4];
    u32 flagsCC;
    u8 pad1[0xd4 - 0xd0];
    Object_vptr_0* h;
    u8 bD8;
    u8 pad2;
    u16 hwDA;
    u8 pad3[0xe8 - 0xdc];
    u32 mdl;
    u8* ec;
    u8* f0;
    u8* f4;
    u8* f8;
    u8* fc;
    u8 b100;
    u8 b101;
    u16 h102;
    u32 flags104;
    u8 pad4[0x110 - 0x108];
    u32 x110;
    u32 x114;
    u32 x118;
    u8 pad5[0x124 - 0x11c];
    Object_vptr_0* p124;
    Object_vptr_0* p128;
    Object_vptr_0* p12c;
    Object_vptr_0* p130;
    Object_vptr_0* p134;

    void* getF4() const {
        return f4 + b101 * rnd32(h102 * 0x30);
    }

    void* getF8() const {
        return f8 ? f8 + b101 * rnd32(h102 * 0x24) : 0;
    }

    void* getFC() const {
        return fc ? fc + b101 * rnd32(h102 * 0x30) : 0;
    }
};

extern "C" {
void fn_801AE08C(void*, void*, void*);
void fn_80197A40(u32*, void*);
void fn_801B55C4(u32*, void*, void*, void*);
void fn_801AAB18(void*, void*);
int fn_8015D804();
void fn_8015D874();
void fn_801D7718(void*, u32);
void fn_801A4204(void*, void*, void*, void*, u32, void*, u32*, void*);
void fn_801A3D68(void*, void*, void*, void*, u32, void*, u32*, void*);
void fn_801A3A44(void*, void*, void*, void*, u32, void*, u32*, void*);
void fn_801A64B0(u32*, void*, void*, void*, u32, u32, u32, u32);
void fn_801AB3C4(void*, u32, void*, void*);
}

static inline void call_801A64B0(
    u32 mdl, void* p4, void* p5, void* p6,
    u32 p7, u32 p8, u32 p9, u32 p10
) {
    fn_801A64B0(&mdl, p4, p5, p6, p7, p8, p9, p10);
}

extern "C" void fn_801AE668(
    Class_80466388* s, u32 arg1, void* arg2, void* arg3
) {
    s32 masked;
    if (arg1 < 9U && ((1U << (arg1 - 1)) & s->flagsCC)) {
        masked = 1;
    } else {
        masked = 0;
    }
    if (masked != 0) {
        return;
    }

    switch ((s32)arg1) {
    case 0x5: {
        Arg3Obj* a3 = (Arg3Obj*)arg3;
        u32 flags = s->flagsCC;
        a3->slot1(s, !(flags & 0x20000000), !(flags & 0x40000000));
        break;
    }
    case 0x1: {
        u32 sp20;
        fn_801AE08C(s, arg2, arg3);
        Object_vptr_0* h2 = s->p128;
        if (h2 != 0) {
            sp20 = s->mdl;
            fn_80197A40(&sp20, h2);
        }
        if (s->h && (s->hwDA & 1) && (s->bD8 & 4)) {
            s->h->slot1(4, s, arg2, arg3);
        }
        break;
    }
    case 0x2: {
        u32 sp1c;
        if (s->h && (s->hwDA & 2) && (s->bD8 & 1)) {
            s->h->slot2(1, s, arg2, arg3);
        }
        Object_vptr_0* p130 = s->p130;
        if (p130 != 0 || s->p134 != 0 || s->p12c != 0) {
            Object_vptr_0* p12c = s->p12c;
            Object_vptr_0* p134 = s->p134;
            sp1c = s->mdl;
            fn_801B55C4(&sp1c, p130, p134, p12c);
        }
        if (s->h && (s->hwDA & 2) && (s->bD8 & 4)) {
            s->h->slot2(4, s, arg2, arg3);
        }
        break;
    }
    case 0x4: {
        u32 sp18;
        u32 sp14;
        u32 sp10;
        s->b101 = (u8)((s->b101 + 1) % s->b100);
        if (s->h && (s->hwDA & 4) && (s->bD8 & 1)) {
            s->h->slot3(1, s, arg2, arg3);
        }
        fn_801AAB18(s, arg3);
        if (s->h && (s->hwDA & 4) && (s->bD8 & 2)) {
            s->h->slot3(2, s, arg2, arg3);
        }
        if (fn_8015D804()) {
            if (s->flags104 & 1) {
                fn_801D7718(s->ec, s->h102 * 0x30);
                void* p4 = s->getF8();
                void* p10 = s->getFC();
                sp10 = s->mdl;
                fn_801A4204(
                    s->getF4(), p4, s->ec, s->f0, s->h102,
                    arg3, &sp10, p10
                );
            } else {
                void* p4 = s->getF8();
                void* p10 = s->getFC();
                sp14 = s->mdl;
                fn_801A3D68(
                    s->getF4(), p4, s->ec, s->f0, s->h102,
                    arg3, &sp14, p10
                );
            }
            fn_8015D874();
        } else {
            void* p4 = s->getF8();
            void* p10 = s->getFC();
            sp18 = s->mdl;
            fn_801A3A44(
                s->getF4(), p4, s->ec, s->f0, s->h102,
                arg3, &sp18, p10
            );
        }
        if (s->h && (s->hwDA & 4) && (s->bD8 & 4)) {
            s->h->slot3(4, s, arg2, arg3);
        }
        break;
    }
    case 0x6: {
        u32 v;
        if (s->h && (s->hwDA & 0x10) && (s->bD8 & 1)) {
            s->h->slot4(1, s, arg2, arg3);
        }
        if (arg3) {
            v = *(u32*)arg3;
        } else {
            v = s->x118;
        }
        void* p5 = s->getF8();
        void* p6 = s->getFC();
        call_801A64B0(
            s->mdl, s->getF4(), p5, p6, s->x110, 0, 0, v
        );
        if (s->h && (s->hwDA & 0x10) && (s->bD8 & 4)) {
            s->h->slot4(4, s, arg2, arg3);
        }
        break;
    }
    case 0x7: {
        u32 v;
        if (s->h && (s->hwDA & 0x20) && (s->bD8 & 1)) {
            s->h->slot5(1, s, arg2, arg3);
        }
        if (arg3) {
            v = *(u32*)arg3;
        } else {
            v = s->x118;
        }
        void* p5 = s->getF8();
        void* p6 = s->getFC();
        call_801A64B0(
            s->mdl, s->getF4(), p5, p6, 0, s->x114, 0, v
        );
        if (s->h && (s->hwDA & 0x20) && (s->bD8 & 4)) {
            s->h->slot5(4, s, arg2, arg3);
        }
        break;
    }
    case 0x8:
        if (s->p124) s->p124->slot7();
        if (s->p128) s->p128->slot7();
        if (s->p12c) s->p12c->slot7();
        if (s->p130) s->p130->slot7();
        if (s->p134) s->p134->slot7();
        break;
    case 0x10001:
        s->fn_801AF6C0(arg3);
        break;
    default:
        fn_801AB3C4(s, arg1, arg2, arg3);
        break;
    }
}
