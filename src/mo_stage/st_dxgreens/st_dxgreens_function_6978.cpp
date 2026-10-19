#pragma force_active on
struct Pair { unsigned int first; unsigned int second; };

struct Data {
    float f00;
    float f04;
    float f08;
    float f0C;
    Pair q10;
    unsigned int w18;
    unsigned int w1C;
    Pair q20;
    unsigned int w28;
    unsigned short h2C;
    unsigned short h2E;
    unsigned char b30;
    unsigned char b31;
    unsigned char b32;
    unsigned char b33;
    unsigned char b34;
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3A;
    unsigned int w3C;
    Pair q40;
    unsigned int w48;
    float f4C;
    unsigned int w50;
    unsigned int w54;
    unsigned int w58;
    unsigned int w5C;
    float f60;
    float f64;
    float f68;
    unsigned int w6C;
    unsigned int w70;
    unsigned int w74;
    unsigned int w78;
    float f7C;
    Pair q80;
    unsigned int w88;
    Pair q8C;
    float f94;
    unsigned int w98;
    unsigned char b9C;
};

struct Interface {
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual Data* getAt(unsigned int index) = 0;
};

extern "C" void fn_79_6978(Interface* self, unsigned int first, unsigned int second) {
    Data* source = self->getAt(first);
    Data* dest = self->getAt(second);
    *dest = *source;
}
