#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

struct VFnIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setA(s32 a);
    virtual void v6();
    virtual void v7();
    virtual void setB(s32 b);
    virtual void setC(f32 a, f32 b, f32 c);
};

struct Holder {
    u8 pad[0xc8];
    VFnIface* iface;
};

struct Self {
    u8 pad0[0xdc];
    u8 acc[0x1b4 - 0xdc];
    Holder* holder;
};

extern "C" float fn_41_3834(Self* self);
extern "C" float fn_41_38B8(Self* self);

extern "C" void fn_41_3C04(Self* self) {
    s32 a = (s32)fn_41_3834(self);
    s32 b = (s32)fn_41_38B8(self);
    f32 f31 = soValueAccesser::getValueFloat((soModuleAccesser*)&self->acc, 0xbcc, 0);
    f32 f30 = soValueAccesser::getValueFloat((soModuleAccesser*)&self->acc, 0xbcd, 0);
    f32 f29 = soValueAccesser::getValueFloat((soModuleAccesser*)&self->acc, 0xbce, 0);
    self->holder->iface->setA(a);
    self->holder->iface->setB(b);
    self->holder->iface->setC(f31, f30, f29);
}
