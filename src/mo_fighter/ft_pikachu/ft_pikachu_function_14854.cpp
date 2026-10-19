#include <so/so_module_accesser.h>
#pragma force_active on

struct PikachuWorkOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

struct PikachuWorkIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int a, int key);
};

extern "C" int fn_98_14854(PikachuWorkOwner* owner, int a) {
    char* m1 = *reinterpret_cast<char**>(reinterpret_cast<char*>(owner->accesser) + 0xd8);
    PikachuWorkIface* obj = *reinterpret_cast<PikachuWorkIface**>(m1 + 0x64);
    return obj->v5(a, 0x10000007);
}
