#pragma force_active on
struct FtBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int v9(int arg);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual void v14();
    virtual void v15();
};

extern "C" int fn_102_17D18(void*, char* obj) {
    FtBase* self = *(FtBase**)(*(char**)(obj + 0xd8) + 0x54);
    int result;
    if (self->v9(0) == 1) {
        FtBase* s2 = *(FtBase**)(*(char**)(obj + 0xd8) + 0x3c);
        result = s2->v13();
    } else {
        result = 0;
    }
    return result;
}
