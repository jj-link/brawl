#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual bool isNull() const;
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int, int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9(int);
    virtual void slot10();
    virtual void slot11(int);
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
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75(int, int, int, int, int);
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual int slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99(int, int, int);
};

struct Sub {
    char pad0[0x28];
    int v28;
};

struct Inner {
    char pad0[0x54];
    soNullable* comp;
};

struct Mid {
    char pad0[0x8];
    Sub* sub;
    char pad1[0xd8 - 0xc];
    Inner* inner;
};

struct Fighter {
    char pad0[0x10];
    Mid* mid;
    int f14;
    int f18;
    char pad1[0x28 - 0x1c];
    float f28;
    char pad2[0x2d - 0x2c];
    u8 f2d;
    u8 f2e;
    char pad3[0x31 - 0x2f];
    u8 f31;
};

extern "C" soNullable* fn_27_8CD94();
extern "C" const float lbl_27_rodata_910[];

extern "C" void fn_27_66A70(Fighter* self) {
    if (self->f2d == 1) {
        if (self->mid->inner->comp->slot88() == 0) {
            self->mid->inner->comp->slot75(0, self->f18, self->f14, 3, 1);
            self->mid->inner->comp->slot99(0, 7, 0);
            self->mid->inner->comp->slot11(0);
            soNullable* p = fn_27_8CD94();
            if (p->slot9(2) == 0 && p->slot4(2, self->mid->sub->v28) == 1U) {
                p->slot99(2, 0, 1);
            }
        }
    }
    self->f2e = 1;
    self->f31 = 0;
    self->f28 = lbl_27_rodata_910[0];
}
