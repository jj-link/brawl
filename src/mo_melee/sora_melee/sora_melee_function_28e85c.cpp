#pragma force_active on
typedef unsigned int u32;

class VA {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int f16(void* a);
};

class VB {
public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual int g9(int a);
};

class VC {
public:
    virtual void h0();
    virtual void h1();
    virtual u32* h2(int a);
};

class NonPolyBase {
public:
    int unk0;
    int unk4;
};

class Subject : public NonPolyBase {
public:
    virtual void p0();
    virtual void p1();
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
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual int test(void* owner);
};

extern "C" int fn_27_28E85C(char* self) {
    VA* sub = (VA*)(*(char**)(*(char**)(self + 0x1a4) + 0x70));
    int var_r3;
    if (sub->f16(*(void**)(self + 0x1a4)) == 2) {
        var_r3 = 1;
    } else {
        var_r3 = ((VB*)(self + 0x27a8))->g9(3);
    }
    if (var_r3 != 0 || (*(Subject**)(self + 0x8d0))->test(self) == 0) {
        return 0;
    }
    u32* p = ((VC*)(self + 0x297c))->h2(8);
    return !(*p & 0x01000000);
}
