#pragma force_active on
struct fnVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int, unsigned int);
};

extern "C" int fn_27_29BA88(void* unused, char* obj) {
    fnVirtBase* c = *(fnVirtBase**)(*(char**)(*(char**)(obj + 0x60) + 0xd8) + 0x64);
    c->f5(-1, 0x10000000);
    return 0;
}
