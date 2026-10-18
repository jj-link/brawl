#pragma force_active on
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
    virtual float get14(unsigned long);
    virtual void set15(unsigned long, float);
    virtual float get16(unsigned long);
};

extern "C" void fn_118_11040(void* self, unsigned char* obj) {
    VObj* p = *(VObj**)(*(unsigned char**)(obj + 0xD8) + 0x64);
    float v = p->get14(0x21000004);
    VObj* q = *(VObj**)(*(unsigned char**)(obj + 0xD8) + 8);
    float w = q->get16(0x1EA);
    float r = -(v / w);
    p->set15(0x21000005, r);
}
