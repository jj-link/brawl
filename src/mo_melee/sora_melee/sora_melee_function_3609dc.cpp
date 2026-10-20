#include <types.h>
#pragma force_active on

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 arg);

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void target(int a, int b, int c);
};

extern "C" void fn_27_3609DC(void* unused, void* acc) {
    VObj* obj = *(VObj**)((char*)*(void**)((char*)acc + 0xd8) + 0x88);
    obj->target(getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x10000036, 0) + 0x11C0002, 1, 1);
}
