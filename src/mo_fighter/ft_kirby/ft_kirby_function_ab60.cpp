#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
int fn_96_AB24(int a, int b, int c);
}

class KirbyFtObj {
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

extern "C" void fn_96_AB60(int arg1, int arg2, int* arr) {
    KirbyFtObj* obj = (KirbyFtObj*)fn_96_AB24(arg1, arg2, (int)arr);
    if (obj->f0() == 1) return;
    if (arr == 0) return;
    int i = 0;
    while (true) {
        int count = obj->f13();
        if (i >= count) break;
        int* p = arr + i * 2;
        int val = *p;
        if (val < 0) break;
        int second = p[1];
        int* result = obj->f1(val);
        *result = second;
        i++;
    }
}
