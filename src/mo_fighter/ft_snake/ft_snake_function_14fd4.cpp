#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f5(unsigned long, unsigned long);
};

extern "C" void fn_122_14FD4(void*, soModuleAccesser* accesser) {
    VObj* obj = *(VObj**)(*(char**)((char*)accesser + 0xd8) + 0x64);
    int v = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5DC0, 0);
    obj->f5(v, 0x20000002);
}
