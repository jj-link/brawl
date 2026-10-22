#pragma force_active on

extern float lbl_27_rodata_2378;
extern float lbl_27_rodata_237C;

class Module {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void setFlag(int a, unsigned int b);
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
    virtual void setFlag2(unsigned int a);
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
    virtual void setParam(int* p, float f);
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual int query39(int a);
    virtual void p38();
    virtual void play(int a, int b, int c, int d, int e, float f, float g);
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual int query45(int a);
};

struct Modules {
    char pad0[8];
    Module* motion;
    char pad1[0x64 - 0x0c];
    Module* sub;
    char pad2[0xa8 - 0x68];
    Module* work;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

struct Param {
    int kind;
    float a;
    float b;
    char c0, c1, c2, c3;
};

extern "C" void fn_27_17C32C(void*, Owner* owner) {
    int r = owner->modules->work->query39(0);
    int ret = owner->modules->motion->query45(1);
    if (ret != -1) {
        int kind = (r == 0) ? 0x16E : 0x166;
        owner->modules->motion->play(1, kind, 0x135, 0, 0, lbl_27_rodata_2378, lbl_27_rodata_237C);
    } else {
        Param p;
        int kind = 0x16A;
        if (r == 0) {
            kind = 0x172;
        }
        p.kind = kind;
        p.a = lbl_27_rodata_2378;
        p.b = lbl_27_rodata_237C;
        p.c0 = 0;
        p.c1 = 0;
        p.c2 = 0;
        p.c3 = 0;
        owner->modules->motion->setParam((int*)&p, lbl_27_rodata_2378);
    }
    owner->modules->sub->setFlag(4, 0x2000000C);
    owner->modules->sub->setFlag2(0x22000012);
}
