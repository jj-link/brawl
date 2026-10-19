#pragma force_active on
class Obj {
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
    virtual int vcall(unsigned int);
};

extern "C" int fn_113_180C8(char* self) {
    char* a = *(char**)(self + 0x60);
    char* b = *(char**)(a + 0xd8);
    Obj* c = *(Obj**)(b + 0x64);
    return c->vcall(0x11000006);
}
