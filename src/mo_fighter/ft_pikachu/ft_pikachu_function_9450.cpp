#include <so/so_module_accesser.h>
#pragma force_active on

struct PikachuVirtualObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f7(int a, int b);
};

extern "C" void fn_98_9450(char* owner) {
    char* p = *reinterpret_cast<char**>(owner + 0x60);
    p = *reinterpret_cast<char**>(p + 0xd8);
    PikachuVirtualObj* obj = *reinterpret_cast<PikachuVirtualObj**>(p + 0x64);
    obj->f7(0, 0x10000042);
}
