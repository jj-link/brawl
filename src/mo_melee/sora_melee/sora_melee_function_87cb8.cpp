#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_13378[];

struct Key {
    s16 v;
    Key(const Key& o) : v(o.v) {}
};

class Idx {
public:
    virtual void a2();
    virtual Idx** a3(s32);
};

class Object_vptr_0 {
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
};

class Top {
public:
    virtual void t2(Key, void*, u32, void*, void*);
    virtual void t3();
};

class Mid {
public:
    u8 pad[0xc];
    Top sub;
};

class Outer {
public:
    u8 pad[0x14];
    Mid* mid;
};

struct Loc {
    void* vt;
    void* p;
    u32 c;
    u8 pad[0x60];

    Loc() {
        vt = lbl_27_data_13378;
        p = lbl_27_data_13378 + 0x48;
        c &= 0x1fff;
    }
};

void fn_27_87CB8(Outer* arg0, u32 arg1, Key arg2) {
    Loc loc;

    arg0->mid->sub.t2(arg2, &loc, loc.c, loc.p, loc.vt);

    if (arg1 == 1) {
        s32 n = (s32)((loc.c << 12) & 0xFE000000) >> 26;
        for (s32 i = 0; i < n; i++) {
            (*(Object_vptr_0**)*((Idx*)&loc)->a3(i))->slot12();
        }
    } else {
        s32 n = (s32)((loc.c << 12) & 0xFE000000) >> 26;
        for (s32 i = 0; i < n; i++) {
            (*(Object_vptr_0**)*((Idx*)&loc)->a3(i))->slot13();
        }
    }
}
}
