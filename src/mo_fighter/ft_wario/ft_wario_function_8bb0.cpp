#include <so/so_module_accesser.h>
#pragma force_active on

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

extern "C" FtObj* fn_110_8B74();

extern "C" void fn_110_8BB0(int a, int b, int* c) {
    FtObj* obj = fn_110_8B74();
    if (obj->f0() == 1) return;
    if (c == 0) return;
    int i = 0;
    while (true) {
        if (i >= obj->f13()) break;
        int* p = c + i * 2;
        int val = *p;
        if (val < 0) break;
        int second = p[1];
        int* dest = obj->f1(val);
        *dest = second;
        i++;
    }
}
