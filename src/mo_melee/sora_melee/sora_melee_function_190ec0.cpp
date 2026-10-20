#pragma force_active on
struct IA {
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
    virtual void v20(unsigned int);
};

struct IB {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
};

extern "C" void fn_27_190EC0(void* unused, char* obj) {
    unsigned int base = 0x22000000;
    char* a = *(char**)(obj + 0xd8);
    IA* b = *(IA**)(a + 0x64);
    b->v20(base + 0x11);
    b->v20(base + 0x12);
    char* c = *(char**)(*(char**)(obj + 0xd8) + 0x7c);
    ((IB*)c)->w9();
}
