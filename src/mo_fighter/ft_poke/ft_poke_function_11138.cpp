#pragma force_active on
extern "C" void fn_27_1DB0E8(void*);

struct LocalArg {
    unsigned int a;
    unsigned char b;
};

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
    virtual void v13();
    virtual void v14();
    virtual int m15(int, void*);
    virtual void v16();
    virtual int m17(unsigned int);
};

extern "C" void fn_116_11138(void* self) {
    fn_27_1DB0E8(self);
    unsigned char* p = *(unsigned char**)((unsigned char*)self + 0x60);
    p = *(unsigned char**)(p + 0xd8);
    VObj* obj = *(VObj**)(p + 0x64);
    if (obj->m17(0x12000004) == 0) {
        LocalArg arg;
        arg.a = 0x456;
        arg.b = 0;
        p = *(unsigned char**)((unsigned char*)self + 0x60);
        p = *(unsigned char**)(p + 0xd8);
        VObj* obj2 = *(VObj**)(p + 0x54);
        obj2->m15(3, &arg);
    }
}
