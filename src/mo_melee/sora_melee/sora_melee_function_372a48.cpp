#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern float lbl_27_rodata_7BC0;
extern double lbl_27_rodata_7BC8;
extern "C" s32 fn_27_30FACC(void*, u32, s32, void*, u32);
extern "C" float fn_27_192278(void*, u32);

struct Vec { float x, y, z; };

class Work {
public:
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual int get(int);
    virtual void set(int, int, void*);
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void on(int);
};

class Status {
public:
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual int get();
};

class Motion {
public:
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void move(Vec*, void*);
};

class Modules {
public:
    char pad[0x64];
    Work* work;
    char pad2[8];
    Status* status;
    char pad3[8];
    Motion* motion;
};

struct OwnerPad { char pad[0x3c]; };
class Owner : public OwnerPad {
public:
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual int get();
};

class Obj {
public:
    char pad[8];
    Owner* owner;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" void fn_27_372A48(void*, Obj* obj) {
    int value = obj->modules->status->get();
    switch (fn_27_30FACC(&lbl_27_bss_7B0C, 0, value, obj, 1)) {
    case 0x117: {
        Modules* m2 = obj->modules;
        m2->work->set(0, 0x20000003, m2);
        break;
    }
    case 0x118: {
        Work* work = obj->modules->work;
        float factor = fn_27_192278(obj, 0xfa6);
        float conv = (float)work->get(0x10000040);
        float x = conv * factor;
        Vec v;
        v.y = lbl_27_rodata_7BC0;
        v.z = lbl_27_rodata_7BC0;
        v.x = -x;
        obj->modules->motion->move(&v, obj);
        break;
    }
    }
    if (obj->owner->get() == 5)
        obj->modules->work->on(0x22000013);
}
