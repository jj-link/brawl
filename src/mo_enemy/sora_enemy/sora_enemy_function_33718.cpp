#pragma force_active on

struct V {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25(int);
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
};

struct C {
    char pad[0x1C];
    V* m_p1C;
    V* m_p20;
};

struct B {
    char pad[0xD8];
    C* m_c;
};

struct Obj {
    char pad[0x6C];
    B* m_b;
    char pad2[0x214C];
    int m_i21BC;
    char pad3[0x14];
    float m_f21D4;
    char pad4[0x41];
    char m_c2219;
};

extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" int fn_41_31E7C(void* self, unsigned int arg1, int arg2);
extern "C" char lbl_41_data_5210[];
extern "C" char lbl_41_data_5239[];
extern "C" float lbl_41_rodata_E54;
extern "C" float lbl_41_rodata_E28;

extern "C" void fn_41_33718(Obj* self) {
    wnemReport__FPCce(lbl_41_data_5210);

    self->m_b->m_c->m_p1C->f4();
    self->m_b->m_c->m_p20->f25(0);

    if (self->m_f21D4 <= lbl_41_rodata_E54)
        self->m_f21D4 = lbl_41_rodata_E28;

    if (self->m_i21BC == 0) {
        self->m_c2219 = 1;
    } else {
        wnemReport__FPCce(lbl_41_data_5239);
        fn_41_31E7C(self, self->m_i21BC, 1);
    }
}
