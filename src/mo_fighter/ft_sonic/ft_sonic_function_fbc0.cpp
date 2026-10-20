#pragma force_active on
struct Obj {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual void v12(unsigned int);
};

extern "C" void fn_123_FBC0(void*, void* obj) {
    char* self = (char*)obj;
    Obj* inner = *(Obj**)(*(char**)(self + 0xd8) + 0x14);
    if (inner->v3() == 0) {
        Obj* target = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
        target->v12(0x21000004);
    } else {
        Obj* target = *(Obj**)(*(char**)(self + 0xd8) + 0x64);
        target->v12(0x21000005);
    }
}
