#pragma force_active on
struct Obj {
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
    virtual void f13(float, unsigned int);
};

extern "C" void fn_113_17F80(char* self, float* arg) {
    Obj* obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f13(arg[0], 0x11000002);

    obj = *(Obj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    obj->f13(arg[1], 0x11000003);
}
