#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
}

class VBase {
public:
    virtual ~VBase();
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
    virtual void call(u32 arg);
};

extern "C" void fn_124_BA30(int unused, void* p2) {
    void* gg = *reinterpret_cast<void**>(reinterpret_cast<u8*>(g_GameGlobal) + 8);
    if (*(reinterpret_cast<u8*>(gg) + 0xf) & 1) {
        VBase* sub = *reinterpret_cast<VBase**>(reinterpret_cast<u8*>(*reinterpret_cast<void**>(reinterpret_cast<u8*>(p2) + 0xd8)) + 0x64);
        sub->call(0x22000011);
    }
    VBase* sub2 = *reinterpret_cast<VBase**>(reinterpret_cast<u8*>(*reinterpret_cast<void**>(reinterpret_cast<u8*>(p2) + 0xd8)) + 0x64);
    sub2->call(0x22000012);
}
