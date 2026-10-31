#include <types.h>
#pragma force_active on

class fn_27_Obj {
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
    virtual void target(u32 p);
};

extern "C" void fn_27_29F980(void* p1, u8* p2, s32 p3) {
    if (p3 == 0) {
        fn_27_Obj* obj = *(fn_27_Obj**)(p2 + 0x60);
        obj = *(fn_27_Obj**)((u8*)obj + 0xD8);
        obj = *(fn_27_Obj**)((u8*)obj + 0x64);
        obj->target(0x12000000);
    }
}
