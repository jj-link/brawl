#include <types.h>
#pragma force_active on

struct Rec {
    u8 kind;
    u8 f01;
    u8 f02;
    u8 pad03;
    u8 f04;
    s8 color;
    u8 costume;
    u8 pad07;
    u8 f08;
    u8 pad09[2];
    u8 f0b;
    u8 pad0c[0x0e];
    u8 f1a;
    u8 f1b;
    u8 pad1c[2];
    u8 f1e;
    u8 f1f;
    u8 pad20[2];
    u16 f22;
    u8 pad24[0x10];
    f32 f34;
    f32 f38;
    u8 pad3c[4];
    f32 f40;
};

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual Rec* slot37();
};

struct Src {
    u8 pad00[4];
    u8 f04;
    u8 pad05;
    u8 f06;
    u8 pad07;
    u16 f08;
    u8 pad0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    f32 f10;
    f32 f14;
    f32 f18;
};

struct Elem {
    u8 pad00[0x26];
    u8 f26;
    u8 f27;
    u8 f28;
    u8 pad29[3];
    f32 f2c;
    f32 f30;
    f32 f34;
};

struct Menu {
    u8 pad0[0x1d4];
    s32 f1d4;
    s32 pad1d8;
    Src* f1dc;
    s32 pad1e0;
    s32 f1e4;
    s32 f1e8;
};

extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
extern "C" int getFighterColorFileNo__6muMenuFiii(int, int);

extern "C" void fn_27_24CDE4(Menu* self, Object_vptr_3c* obj, s32 kind, s32 costume, s32 arg4, s32 flag)
{
    Rec* r = obj->slot37();
    r->kind = (u8)kind;
    r->f01 = 1;
    r->f02 = (u8)arg4;
    r->f0b = 1;

    s32 m = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
    s32 color;
    if (m == 0x28) {
        color = 0;
    } else {
        color = getFighterColorFileNo__6muMenuFiii(m, costume);
    }
    r->color = (s8)color;
    r->costume = (u8)costume;
    r->f1b = (u8)(r->f1b | 0x80);

    if (self->f1dc->f04 == 0) {
        s32 t;
        u8 e;
        if (self->f1dc->f0b != 0) {
            e = self->f1dc->f0b;
        } else {
            t = self->f1e8;
            e = 7;
            self->f1e8 = t + 1;
            if (t & 1) {
                e = 0;
            }
        }
        r->f1e = e;
        r->f1f = self->f1dc->f0c;
        r->f1a = self->f1dc->f06;
        r->f22 = self->f1dc->f08;
        r->f34 = self->f1dc->f10;
        r->f38 = self->f1dc->f14;
        r->f40 = self->f1dc->f18;
        r->f04 = 1;
    } else {
        r->f1a = self->f1dc->f06;
        Elem* el = (Elem*)((u8*)self->f1dc + self->f1d4 * 0x14);
        u8 c = el->f26;
        r->f04 = ((s8)c >= 1) ? c : 1;
        r->f1e = el->f27;
        r->f1f = el->f28;
        r->f34 = el->f2c;
        r->f38 = el->f30;
        r->f40 = el->f34;
    }
    if (flag == 0) {
        r->f08 = 0x1e;
    }
    self->f1e4 = self->f1e4 + 1;
}
