#pragma force_active on

extern "C" const float lbl_27_rodata_2B38;

struct ABase {
    char pad[8];
};

struct A : ABase {
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
    virtual int m42();
};

struct B {
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
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void q30();
    virtual void q31();
    virtual void q32();
    virtual void q33();
    virtual void m36(int, void*);
};

struct C {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void m9(float, void*);
};

struct Obj {
    char pad0[8];
    C* p8;
    char pad1[0x64];
    B* p70;
    char pad2[0x28];
    A* p9c;
};

struct Owner {
    char pad[0xD8];
    Obj* obj;
};

extern "C" void fn_27_1DE198(void*, Owner* self) {
    A* a = self->obj->p9c;
    if (a->m42() == 2) {
        self->obj->p70->m36(2, self);
        self->obj->p8->m9(lbl_27_rodata_2B38, self->obj);
    }
}
