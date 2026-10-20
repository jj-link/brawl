#pragma force_active on
extern "C" void fn_27_25380(float* dst, const float* src);

class IVirt {
public:
    int pad0;
    int pad1;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(const float* src, int flag);
};

extern "C" void fn_27_236B0(void* self, const float* src) {
    fn_27_25380((float*)self, src);
    char* a = *(char**)((char*)self + 0x8);
    char* b = *(char**)(a + 0xd8);
    IVirt* c = *(IVirt**)(b + 0x10);
    c->v9(src, 0);
}
