#pragma force_active on

struct P {
    unsigned int a[2];
};

class Data {
public:
    virtual void v0();
    unsigned char b0;
    P p0, p1, p2, p3, p4, p5, p6;
    unsigned int w1;
    P p7, p8;
    unsigned int w2;
    unsigned char c[32];
    unsigned char d0, d1, d2, d3, d4, d5, d6, d7, d8, d9,
                 d10, d11, d12, d13, d14, d15, d16, d17;
};

class Vt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual Data* get(unsigned int);
};

extern "C" Data* fn_27_1B8C24(Vt* self, unsigned int srcIndex, unsigned int dstIndex) {
    Data* src = self->get(srcIndex);
    Data* dst = self->get(dstIndex);
    *dst = *src;
    return dst;
}