#include <so/so_module_accesser.h>
#pragma force_active on

class FtObj {
public:
    virtual unsigned int f2() = 0;
    virtual int* f3(int key) = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual int f15() = 0;
};

struct FtPair {
    int key;
    int value;
};

extern "C" FtObj* fn_125_9F3C(int a, int b, int c);

extern "C" void fn_125_9F78(int a, int b, FtPair* c) {
    FtObj* obj = fn_125_9F3C(a, b, (int)c);
    if (obj->f2() == 1) return;
    if (c == 0) return;

    int i = 0;
    while (true) {
        int count = obj->f15();
        if (i >= count) break;

        FtPair* p = &c[i];
        int key = p->key;
        if (key < 0) break;

        int value = p->value;
        int* dst = obj->f3(key);
        *dst = value;
        i++;
    }
}
