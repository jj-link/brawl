#pragma force_active on
class Iface {
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
    virtual int v12();
};

extern "C" {
int fn_27_8CCE0(void* self) {
    void* a = *(void**)((char*)self + 0x60);
    void* b = *(void**)((char*)a + 0xD8);
    Iface* c = *(Iface**)((char*)b + 0x64);
    return c->v12();
}
}
