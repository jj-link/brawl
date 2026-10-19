#pragma force_active on
extern "C" void fn_96_D5C4(void*, void*, int);

struct VBase {
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
    virtual int check(unsigned int flag);
};

extern "C" void fn_96_AF30(unsigned char* self) {
    unsigned char* a = *(unsigned char**)(self + 0x60);
    unsigned char* b = *(unsigned char**)(a + 0xd8);
    VBase* c = *(VBase**)(b + 0x64);
    if (c->check(0x12000042)) {
        fn_96_D5C4(self, *(void**)(self + 0x60), 0);
    }
}
