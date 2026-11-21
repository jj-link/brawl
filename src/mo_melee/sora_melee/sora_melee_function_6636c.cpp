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

class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*);
    virtual u32 slot4(int, int, u32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual int slot8(int);
    virtual int slot9(int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, void*);
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
    virtual void slot88();
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
    char pad0[0x3c];
    soNullable* p3c;
    char pad1[0x54 - 0x40];
    VObj* p54;
    char pad2[0x70 - 0x58];
    VObj* p70;
};

struct Mid {
    char pad0[0x8];
    Sub* sub;
    char pad1[0xd8 - 0xc];
    Inner* inner;
};

struct Msg {
    int a;
    u8 flag;
    int idx;
    int arg;
    float f18;
    float f1c;
    int i20;
    u8 f24;
};

struct Fighter {
    char pad0[0x10];
    Mid* mid;
    int f14;
    int f18;
    char pad1[0x24 - 0x1c];
    int f24;
    float f28;
    u8 f2c;
    u8 f2d;
    u8 f2e;
    u8 f2f;
    char pad2[0x31 - 0x30];
    u8 f31;
};

extern "C" void* getTask__6gfTaskFi(int);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" const char lbl_27_data_248[];
extern "C" const char __RTTI__6gfTask[];
extern "C" const float lbl_27_rodata_910[];
extern "C" VObj* fn_27_8CDA4(void*);
extern "C" soNullable* fn_27_8CD94(void*);

extern "C" int fn_27_6636C(Fighter* self, int taskId, int arg2, u32 arg3) {
    if (self->mid->inner->p54->slot4(0, taskId, arg3) == 1U) {
        Msg m;
        m.a = 8;
        m.flag = 0;
        m.idx = -1;
        m.arg = arg2;
        m.f18 = lbl_27_rodata_910[0];
        m.f1c = lbl_27_rodata_910[0];
        m.i20 = 0;
        m.f24 = 1;
        self->mid->inner->p54->slot15(0, &m);
        if (m.flag == 1) {
            self->mid->inner->p3c->slot8();
            void* task = getTask__6gfTaskFi(taskId);
            soNullable* cast = (soNullable*)__dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);
            u8 f24 = m.f24;
            self->f2d = f24;
            if (f24 == 1) {
                self->f14 = m.idx;
            }
            self->f24 = m.i20;
            if (arg2 != -1) {
                self->mid->inner->p70->slot3(arg2, self->mid);
            }
            self->f2c = 1;
            self->f2e = 0;
            self->f31 = 0;
            self->f2f = 1;
            self->f28 = lbl_27_rodata_910[0];
            fn_27_8CDA4(cast)->slot7();
            if (arg3 == 1U && self->f2d == 1) {
                soNullable* link = fn_27_8CD94(cast);
                self->mid->inner->p54->slot75(0, self->f18, self->f14, 3, 1);
                if (link->slot9(2) == 0 && link->slot4(2, self->mid->sub->v28) == 1U) {
                    link->slot99(2, 0, 1);
                }
            }
            return 1;
        }
        self->mid->inner->p54->slot8(0);
    }
    return 0;
}
