#include <so/so_module_accesser.h>
#pragma force_active on

class FtObj {
public:
    virtual unsigned int f2() = 0;
    virtual int* f3(int arg) = 0;
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

extern "C" FtObj* fn_123_8B78();

extern "C" void fn_123_8BB4(int, int, int* c) {
    FtObj* obj = fn_123_8B78();
    if (obj->f2() == 1) return;
    if (c == 0) return;

    int i = 0;
    while (true) {
        int count = obj->f15();
        if (i >= count) break;
        int* p = c + i * 2;
        int val = *p;
        if (val < 0) break;
        int second = p[1];
        int* result = obj->f3(val);
        *result = second;
        i++;
    }
}
