#pragma force_active on
extern "C" void* fn_41_A674(void*);

struct VIface {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual void callB(unsigned long, void*);
    virtual int v16();
    virtual int callA(unsigned long);
};

extern "C" {
void* fn_41_68074(void* self) {
    void* r = fn_41_A674(self);
    unsigned char* s = reinterpret_cast<unsigned char*>(self);
    VIface* o = *reinterpret_cast<VIface**>(s + 0x1b4);
    o = *reinterpret_cast<VIface**>(reinterpret_cast<unsigned char*>(o) + 0x64);
    if (o->callA(0x12000005) != 0) {
        struct Tmp {
            unsigned int a;
            unsigned char b;
        } t;
        t.a = 0x1005;
        t.b = 0;
        VIface* q = *reinterpret_cast<VIface**>(s + 0x60);
        q = *reinterpret_cast<VIface**>(reinterpret_cast<unsigned char*>(q) + 0xd8);
        q = *reinterpret_cast<VIface**>(reinterpret_cast<unsigned char*>(q) + 0x54);
        q->callB(3, &t);
    }
    return r;
}
}
