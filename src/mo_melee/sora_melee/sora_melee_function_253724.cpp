#include <types.h>
#pragma force_active on

extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int kind);
extern "C" int getFighterColorFileNo__6muMenuFiii(int kind, int costume);
extern "C" s32 randi__Fl(long range);
extern "C" void fn_27_254360(void *self, u32 arg1);
extern f32 lbl_27_rodata_4104;

class gfTask_base {
public:
    char pad[0x3c];
};

class Obj : public gfTask_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void *slot37();
};

struct MuFnObj {
    char pad0[0x1b8];
    s32 w1b8;
    s32 w1bc;
    char pad1[0x10];
    s32 w1d0;
    s32 w1d4;
    char pad2[0x84];
    u8 *p25c;
    s32 w260;
    s32 w264;
};

struct Ent {
    char p0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    char p5[3];
    f32 f8;
    f32 fC;
};

struct Out {
    u8 b0;
    u8 b1;
    s8 b2;
    char p3;
    u8 b4;
    s8 b5;
    s8 b6;
    char p7;
    s8 b8;
    s8 b9;
    char pA;
    u8 bB;
    char pC[0x12];
    u8 b1E;
    u8 b1F;
    char p20[0xC];
    f32 f2C;
    char p30[4];
    f32 f34;
    f32 f38;
};

extern "C" void fn_27_253724(MuFnObj *self, Obj *obj, u8 kind, u8 costume, s8 arg4) {
    Out *o = (Out *)obj->slot37();
    Ent *e = (Ent *)(self->p25c + (self->w1d4 << 4));
    s32 sel;
    s32 n;
    s32 avail;
    s32 t;

    o->b0 = kind;
    o->b1 = 1;
    o->b2 = arg4;
    o->b4 = 1;
    o->bB = 1;

    sel = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
    o->b5 = (sel == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(sel, costume);
    o->b6 = costume;
    o->b1E = e->b4;
    o->b1F = e->b3;
    o->f2C = 0.66666f;
    o->f34 = e->f8;
    o->f38 = e->fC;

    o->b9 = (randi__Fl(0x40) < 0x20) ? 1 : -1;

    if (kind >= 0x2e) {
        o->b8 = arg4 + 0x14;
    } else {
        o->b8 = arg4 + 0xa;
    }

    avail = self->w1bc - self->w1b8;
    n = e->b1;
    if (avail < n) {
        n = avail;
    }
    self->w1d0 = n;

    if (e->b2 == 0xff) {
        t = self->w264 + 1;
        self->w264 = t;
        if (self->w260 <= t) {
            fn_27_254360(self, kind);
        }
    }
}
