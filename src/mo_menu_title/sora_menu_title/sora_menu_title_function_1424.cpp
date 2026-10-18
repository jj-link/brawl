#pragma force_active on
class VObj {
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
    virtual void v12();
    virtual void f13(void* arg);
};

extern "C" void fn_24_1424(void* self) {
    unsigned char* p = (unsigned char*)self;
    VObj* obj = *(VObj**)(*(unsigned char**)(p + 0x44) + 0x48);
    void* arg = *(void**)(*(unsigned char**)(p + 0x48) + 0x0C);
    obj->f13(arg);
}
