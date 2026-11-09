#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct V2 {
    f32 x;
    f32 y;
};

struct KineticOps {
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual unsigned long long m14(const unsigned short&);
};

struct Local {
    u8 b8;
    u8 b9;
    unsigned short attributes;
    V2 vectors[5];
    unsigned int sum[2];
    Vec2f speed;
};

extern "C" const float lbl_110_rodata_98;
extern "C" void fn_110_B860(V2* dst, const V2* src);

extern "C" void fn_110_143E4(void* policy, void* self, soModuleAccesser* accesser) {
    Local local;
    KineticOps* kinetic = reinterpret_cast<KineticOps*>(&accesser->getKineticModule());

    local.attributes = 1;
    *reinterpret_cast<unsigned long long*>(local.sum) = kinetic->m14(local.attributes);
    Vec2f::copy(local.speed, *reinterpret_cast<Vec2f*>(local.sum));
    kinetic->m13();

    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    float fbd = params->getParamFloat(accesser, 0xfbd, 0);
    float fa9 = params->getParamFloat(accesser, 0xfa9, 0);
    params->getParamFloat(accesser, 0xfa8, 0);
    float fa6 = params->getParamFloat(accesser, 0xfa6, 0);
    float faa = params->getParamFloat(accesser, 0xfaa, 0);

    local.b9 = 0;
    local.vectors[4].x = local.speed.m_x;
    local.vectors[4].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x18), &local.vectors[4]);

    local.vectors[3].x = lbl_110_rodata_98;
    local.vectors[3].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x20), &local.vectors[3]);

    local.vectors[2].x = fbd;
    local.vectors[2].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x30), &local.vectors[2]);

    local.vectors[1].x = lbl_110_rodata_98;
    local.vectors[1].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x28), &local.vectors[1]);

    local.vectors[0].x = fa6;
    local.vectors[0].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x38), &local.vectors[0]);

    *((unsigned char*)self + 0x15) |= 0x80;
    local.b8 = 0;
    *(f32*)((char*)self + 0x58) = local.speed.m_y;
    *(f32*)((char*)self + 0x5c) = -fa9;
    *(f32*)((char*)self + 0x60) = faa;
    *((unsigned char*)self + 0x55) |= 0x80;
}
