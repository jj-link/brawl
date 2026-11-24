#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_27_data_13378[];
extern int fn_27_8C964(void*);

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
};

class Top {
public:
    virtual void t2(Key k, void* list, void* p);
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
    u8 pad2[4];
    void* ctx;
};

struct Loc {
    void* vt;
    void* p;
    u32 c;
    u8 pad[0x58];

    Loc() {
        vt = lbl_27_data_13378;
        p = lbl_27_data_13378 + 0x48;
        c &= 0x1fff;
    }
};

void fn_27_87868(Outer* arg0, Key arg1) {
    if (fn_27_8C964(arg0->ctx) != 0) {
        Loc loc;
        arg0->mid->sub.t2(arg1, &loc, loc.p);

        s32 n = (s32)((loc.c << 12) & 0xFE000000) >> 26;
        for (s32 i = 0; i < n; i++) {
            (*(Object_vptr_0**)*((Idx*)&loc)->a3(i))->slot6();
        }
    }
}
}
