#pragma force_active on

struct SubIf {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void setA(int, unsigned long);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void setB(float, unsigned long);
};

struct Holder {
    char pad[0x64];
    SubIf* sub;
};

struct Obj {
    char pad[0xd8];
    Holder* holder;
};

extern "C" const float lbl_113_rodata_110;

extern "C" void fn_113_263DC(void*, Obj* obj) {
    obj->holder->sub->setA(0x3c, 0x20000001);
    obj->holder->sub->setA(0x3c, 0x20000000);
    obj->holder->sub->setB(lbl_113_rodata_110, 0x21000001);
}
