#include <types.h>
#pragma force_active on

class fn_27_1B1808_Iface {
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
    virtual void target();
};

class fn_27_1B1808_Holder {
public:
    u32 unk0;
    u32 unk4;
    fn_27_1B1808_Iface* unk8;
};

extern "C" void fn_27_1B1808(fn_27_1B1808_Holder* self) {
    self->unk8->target();
}
