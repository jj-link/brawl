#pragma force_active on
class fnVt {
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
    virtual int v13(int, int, int);
};

extern "C" int fn_27_16A860(void* unused, char* obj) {
    fnVt* inner = *(fnVt**)(*(char**)(obj + 0xd8) + 0x24);
    return inner->v13(0, 0, 0);
}
