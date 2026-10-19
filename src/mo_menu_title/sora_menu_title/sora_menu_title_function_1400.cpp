#pragma force_active on
struct VBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11(void* p, void* q);
};

extern "C" void fn_24_1400(char* self) {
    char* a = *(char**)(self + 0x44);
    char* b = *(char**)(self + 0x48);
    VBase* c = *(VBase**)(a + 0x48);
    char* d = *(char**)(b + 0x0C);
    c->f11(*(void**)((char*)c + 0xE4), d);
}
