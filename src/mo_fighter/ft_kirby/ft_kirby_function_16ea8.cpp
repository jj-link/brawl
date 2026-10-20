#pragma force_active on
extern "C" void fn_96_17638(void* a, void* b);

struct VObj {
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
    virtual int v16();
};

extern "C" void fn_96_16EA8(void* a, void* b) {
    VObj* p = *(VObj**)((char*)b + 0xd8);
    VObj* q = *(VObj**)((char*)p + 0x70);
    switch (q->v16()) {
    case 0x11e:
        fn_96_17638(a, b);
        break;
    default:
        break;
    }
}
