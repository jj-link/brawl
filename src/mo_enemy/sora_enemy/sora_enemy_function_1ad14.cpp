#pragma force_active on
extern "C" {
extern unsigned char lbl_41_data_2B34[];
extern unsigned char lbl_41_data_2A9C[];
void fn_27_D334C(void*, int, void*, int);
void fn_41_1CC18(void*);
}

struct Embedded {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
};

struct Object {
    void* vtable;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char padding[0xC8 - 7];
    Embedded* pointer;
    Embedded embedded;
};

extern "C" Object* fn_41_1AD14(Object* p) {
    p->field4 = 0;
    p->field5 |= 0x80;
    p->field6 = 0;
    p->vtable = lbl_41_data_2B34;
    p->pointer = &p->embedded;
    fn_27_D334C(&p->embedded, 2, lbl_41_data_2A9C, 0);
    p->embedded.method13();
    fn_41_1CC18(p);
    return p;
}
