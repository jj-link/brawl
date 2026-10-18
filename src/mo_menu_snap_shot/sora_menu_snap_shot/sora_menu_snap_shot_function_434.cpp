#pragma force_active on
struct VObj {
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
    virtual void f11(void* a, int b);
};

extern "C" void fn_8_434(char* self, int arg) {
    char* z = *(char**)(self + 0x1ac);
    char* y = *(char**)(z + 0x1d0c);
    char* x = *(char**)(y + 0x35c);
    char* q = *(char**)x;
    VObj* p = (*(unsigned char*)(q + 0x1a4) != 0) ? *(VObj**)(q + 0x48) : 0;
    p->f11(*(void**)((char*)p + 0xe4), arg);
}
