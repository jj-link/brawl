#pragma force_active on
struct Pair {
    int a;
    int b;
};

struct Data {
    float f00;
    float f04;
    float f08;
    float f0C;
    Pair p10;
    int w18;
    int w1C;
    Pair p20;
    int w28;
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
    int w3C;
    Pair p40;
    int w48;
    float f4C;
    int w50;
    int w54;
    int w58;
    int w5C;
    float f60;
    float f64;
    float f68;
    int w6C;
    int w70;
    int w74;
    int w78;
    float f7C;
    Pair p80;
    int w88;
    Pair p8C;
    float f94;
    int w98;
    unsigned char b9C;
};

class Owner {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v0A() {}
    virtual void v0B() {}
    virtual void v0C() {}
    virtual void v0D() {}
    virtual void v0E() {}
    virtual void v0F() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual Data* getData(int index);
};

extern "C" void fn_66_B3E8(Owner* self, int a, int b) {
    Data* src = self->getData(a);
    Data* dst = self->getData(b);
    *dst = *src;
}
