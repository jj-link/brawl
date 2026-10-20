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
    virtual void v13();
    virtual void target(void* x);
};

extern "C" void fn_27_6678(char* a, int b, int c, char* d) {
    char* p = *(char**)(a + 0x60);
    char* q = *(char**)(d + 0x8);
    char* s = *(char**)(p + 0xd8);
    char* t = *(char**)(q + 0x28);
    Obj* obj = *(Obj**)(s + 0x84);
    obj->target(t);
}
