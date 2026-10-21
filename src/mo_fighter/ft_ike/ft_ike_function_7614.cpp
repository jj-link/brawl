#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
int fn_119_75D8(int a, int b, int c);
}

class FtObj {
public:
    virtual unsigned int f0() = 0;
    virtual int* f1(int arg) = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual int f13() = 0;
};

extern "C" void fn_119_7614(int a, int b, int* c) {
    FtObj* obj = (FtObj*)fn_119_75D8(a, b, (int)c);
    if (obj->f0() == 1) return;
    if (c == 0) return;
    int i = 0;
    while (true) {
        int count = obj->f13();
        if (i >= count) break;
        int* p = c + i * 2;
        int val = *p;
        if (val < 0) break;
        int second = p[1];
        int* result = obj->f1(val);
        *result = second;
        i++;
    }
}
