#pragma force_active on
class Sec {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual int get();
};

class Outer {
public:
    int pad[4];
    Sec sec;
};

extern "C" int fn_27_1C6778(Outer* o) {
    Sec* p = &o->sec;
    return p->get();
}
