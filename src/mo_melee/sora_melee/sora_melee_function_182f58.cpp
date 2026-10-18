#include <types.h>
#pragma force_active on

class VBase {
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
    virtual int v15();
    virtual void v16();
    virtual void v17();
};

extern "C" {
int fn_27_182F58(int, void* p4) {
    VBase* obj = *(VBase**)(*(u8**)((u8*)p4 + 0xd8) + 0x40);
    return obj->v15();
}
}
