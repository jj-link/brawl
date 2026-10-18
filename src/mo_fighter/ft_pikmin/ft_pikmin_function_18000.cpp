#pragma force_active on
struct IFace {
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
    virtual void setValue(float f, unsigned int id);
};

extern "C" void fn_113_18000(unsigned char* self, float* p) {
    IFace* obj = *(IFace**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0x64);
    obj->setValue(p[0], 0x11000004u);

    obj = *(IFace**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0x64);
    obj->setValue(p[1], 0x11000005u);
}
