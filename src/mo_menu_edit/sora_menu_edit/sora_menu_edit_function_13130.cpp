#pragma force_active on
struct VirtObj {
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
    virtual void* target();
};

extern "C" void* fn_5_13130(unsigned char* self) {
    unsigned char* a = *(unsigned char**)(self + 0x1ac);
    unsigned char* b = *(unsigned char**)(a + 0x1d3c);
    unsigned char* c = *(unsigned char**)(b + 0x35c);
    unsigned char* d = *(unsigned char**)c;
    VirtObj* obj;
    if (d[0x1a4] != 0) {
        obj = *(VirtObj**)(d + 0x48);
    } else {
        obj = 0;
    }
    return obj->target();
}
