#pragma force_active on

struct Pair {
    unsigned int a;
    unsigned int b;
};

struct Data {
    unsigned char b0;
    unsigned int w4;
    unsigned int w8;
    unsigned int wC;
    unsigned int w10;
    Pair p14;
    Pair p1c;
    unsigned int w24;
    Pair p28;
    unsigned int w30;
    float f34;
    unsigned int w38;
    unsigned char b3c;
};

class C {
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
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual Data* get(void* p);
};

extern "C" void fn_27_EB134(C* self, void* unused, void* arg) {
    Data* src = self->get(unused);
    Data* dst = self->get(arg);
    *dst = *src;
}
