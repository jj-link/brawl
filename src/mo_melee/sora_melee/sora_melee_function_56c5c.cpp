#include <types.h>
#pragma force_active on

// Matches the original except 3 lines in the case 0/12 block: the temporary
// holding the second argument's value is allocated to r0 instead of r5.

struct ArgVal {
    s32 type;
    s32 value;
};

struct Arg {
    ArgVal* p;
    u8 null;
};

struct Ent {
    u8 pad0[0x0d];
    u8 f0d;
    u8 pad1[0x14 - 0x0e];
    s32 f14;
    u8 pad2[0x25 - 0x18];
    u8 f25;
    u8 pad3[0x2c - 0x26];
    s32 f2c;
    u8 pad4[0x3d - 0x30];
    u8 f3d;
    u8 pad5[0x44 - 0x3e];
    s32 f44;
};

extern u8* lbl_27_bss_5668;
extern "C" Ent* fn_27_227F8C(u8* p, s32 n);
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 arg);

class CmdA {
public:
    virtual void slot0();
    virtual s32 slot1();
    virtual s8 slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual u32 slot6(Arg* out, s32 which);
};

struct Pad8 {
    s32 pad_a;
    s32 pad_b;
};

class D : public Pad8 {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54();
    virtual u32 m55(s32 a, s32 b);
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61();
    virtual s32 m62(s32 a, s32 b);
};

class E {
public:
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void e4();
    virtual void e5(s32 a, s32 b);
};

struct Mods {
    u8 pad0[0x10];
    D* f10;
    u8 pad1[0x64 - 0x14];
    E* f64;
};

struct Acc {
    u8 pad0[0xd8];
    Mods* mods;
};

class SubC {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual s32 g3(s32 a, Acc* acc);
    virtual s32 g4(s32 a, Acc* acc);
};

class SelfB {
public:
    virtual void h08(); virtual void h0C(); virtual void h10(); virtual void h14();
    virtual void h18();
    virtual s32 h1C(s32 a, s32 b, s32 c, s32 d);
    virtual s32 h20(s32 a, s32 b);
    virtual void h24();
    virtual void h28(s32 a, s32 b, s32 c);
    virtual void h2C();
    virtual void h30(s32 a);
    virtual void h34(); virtual void h38(); virtual void h3C(); virtual void h40();
    virtual void h44(); virtual void h48(); virtual void h4C(); virtual void h50();
    virtual void h54(s32 a, s32 b);
    virtual void h58(s32 a, s32 b);
    virtual void h5C();
    virtual void h60();
    virtual void h64(); virtual void h68();
    virtual void h6C();
    virtual void h70(); virtual void h74(); virtual void h78(); virtual void h7C();
    virtual void h80(); virtual void h84(); virtual void h88(); virtual void h8C();
    virtual void h90(); virtual void h94(); virtual void h98(); virtual void h9C();
    virtual void hA0(); virtual void hA4(); virtual void hA8(); virtual void hAC();
    virtual void hB0(); virtual void hB4(); virtual void hB8(); virtual void hBC();
    virtual void hC0(); virtual void hC4();
    virtual s32 hC8(s32 a);
    u8 pad_4[0x40];
    SubC* m44;
    s32 m48;
};

extern "C" int fn_27_56C5C(SelfB* self, CmdA* cmd, Acc* acc) {
    u8 nul;
    s32 k = cmd->slot1();
    if (self->hC8((s8)k) == 0) {
        return 0;
    }
    if (cmd->slot2() <= -1 || cmd->slot2() >= 14) {
        return 0;
    }
    switch (cmd->slot2()) {
    case 0:
    case 12: {
        s32 r5;
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 r28 = (a.null == 1) ? 0 : a.p->value;
        if (cmd->slot2() == 0) {
            r28 = self->h1C(r28, 1, 0, 0);
        } else {
            r28 = self->h20(r28, 1);
        }
        if (cmd->slot6(&a, 1) == 1) {
            nul = a.null;
            if (nul == 1) {
                r5 = 0;
            } else {
                r5 = a.p->value;
            }
            if (r5 >= 0) {
                acc->mods->f64->e5(r28, r5);
            }
        }
        return 1;
    }
    case 2: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 v = (a.null == 1) ? 0 : a.p->value;
        self->h28(v, 1, 0);
        return 1;
    }
    case 3: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 v = (a.null == 1) ? 0 : a.p->value;
        self->h54(v, 0);
        return 1;
    }
    case 4: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 v = (a.null == 1) ? 0 : (a.p->value != 0);
        self->h30(v);
        return 1;
    }
    case 5: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 v = (a.null == 1) ? 0 : a.p->value;
        self->h1C(v, 1, 1, 0);
        return 1;
    }
    case 6:
        self->h2C();
        return 1;
    case 7: {
        s32 v = 0;
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        if (a.null == 1) {
            v = 0;
        } else {
            v = a.p->value;
        }
        self->m48 = v;
        return 1;
    }
    case 8:
        self->h60();
        return 1;
    case 1: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        u8 flag = 1;
        if (acc->mods->f10->m55(8, 0) == 1) {
            s32 id = acc->mods->f10->m62(8, 0);
            if (id != 0) {
                Ent* e = fn_27_227F8C(lbl_27_bss_5668 + 0xF8, id);
                self->h1C(e->f14, 1, 0, 0);
                flag = e->f0d;
            }
        }
        if (flag == 1) {
            s32 v = (a.null == 1) ? 0 : a.p->value;
            s32 res = self->m44->g3(v, acc);
            self->h1C(res, 1, 0, 0);
        }
        return 1;
    }
    case 9: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        u8 flag = 1;
        if (acc->mods->f10->m55(8, 0) == 1) {
            s32 id = acc->mods->f10->m62(8, 0);
            if (id != 0) {
                Ent* e = fn_27_227F8C(lbl_27_bss_5668 + 0xF8, id);
                self->h1C(e->f2c, 1, 0, 0);
                flag = e->f25;
            }
        }
        if (flag == 1) {
            s32 v = (a.null == 1) ? 0 : a.p->value;
            s32 res = self->m44->g4(v, acc);
            self->h1C(res, 1, 0, 0);
        }
        return 1;
    }
    case 10: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        u8 flag = 1;
        if (acc->mods->f10->m55(8, 0) == 1) {
            s32 id = acc->mods->f10->m62(8, 0);
            if (id != 0) {
                Ent* e = fn_27_227F8C(lbl_27_bss_5668 + 0xF8, id);
                self->h1C(e->f44, 1, 0, 0);
                flag = e->f3d;
            }
        }
        if (flag == 1) {
            s32 v = (a.null == 1) ? 0 : a.p->value;
            s32 res = self->m44->g4(v, acc);
            self->h1C(res, 1, 0, 0);
        }
        return 1;
    }
    case 11:
        self->h6C();
        return 1;
    case 13: {
        Arg a;
        a.p = 0;
        a.null = 0;
        cmd->slot6(&a, 0);
        s32 type = (a.null == 1) ? -1 : a.p->type;
        s32 r28;
        if (type == 5) {
            r28 = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, (a.null == 1) ? 0 : a.p->value, 0);
        } else {
            r28 = (a.null == 1) ? 0 : a.p->value;
        }
        s32 r30 = 0;
        if (cmd->slot6(&a, 1) == 1) {
            r30 = (a.null == 1) ? 0 : a.p->value;
        }
        self->h58(r28, r30);
        return 1;
    }
    }
    return 0;
}
