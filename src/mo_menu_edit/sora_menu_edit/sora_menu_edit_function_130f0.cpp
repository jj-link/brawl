#pragma force_active on
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
    virtual int f13(int, int);
};

extern "C" int fn_5_130F0(char* self, int arg) {
    char* p = *(char**)(self + 0x1ac);
    p = *(char**)(p + 0x1d3c);
    p = *(char**)(p + 0x35c);
    char* obj = *(char**)p;
    VBase* t;
    if (((unsigned char*)obj)[0x1a4] != 0) {
        t = *(VBase**)(obj + 0x48);
    } else {
        t = 0;
    }
    return t->f13(*(int*)((char*)t + 0xe4), arg);
}
