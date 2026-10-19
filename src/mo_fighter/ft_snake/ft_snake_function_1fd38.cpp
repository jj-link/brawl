#pragma force_active on
struct Obj {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual int f48();
    virtual void d18();
    virtual void d19();
    virtual void f54(int);
};

extern "C" void fn_27_5A78(void*);

extern "C" void fn_122_1FD38(void* p) {
    void* a = *(void**)((char*)p + 0x60);
    void* b = *(void**)((char*)a + 0xD8);
    Obj* c = *(Obj**)((char*)b + 0x70);

    if (c->f48() == 1) {
        a = *(void**)((char*)p + 0x60);
        b = *(void**)((char*)a + 0xD8);
        c = *(Obj**)((char*)b + 0x64);
        c->f54(0x22000000);
    }

    fn_27_5A78(p);
}
