#include <types.h>
#pragma force_active on

struct Dispatcher {
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
    virtual void f11();
    virtual void f12();
    virtual void f13(void* arg);
};

extern "C" Dispatcher* lbl_805A02DC;

extern "C" void fn_800E407C(char* self) {
    int i = 2;
    char* p = self + 8;
    do {
        lbl_805A02DC->f13(*(void**)(*(char**)(p + 0x28) + 0x10));
        i++;
        p += 4;
    } while (i < 6);
    p = self + 0x18;
    int j = 6;
    do {
        lbl_805A02DC->f13(*(void**)(*(char**)(p + 0x28) + 0x10));
        j++;
        p += 4;
    } while (j < 0x18);
}
