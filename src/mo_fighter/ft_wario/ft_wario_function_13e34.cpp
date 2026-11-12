#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct V2 { f32 x; f32 y; };
struct KineticView : soNullable {
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy*, int, soKineticEnergy::AttributeFlag, short);
    virtual void eraseEnergy(int);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int);
    virtual bool isContain(int);
    virtual void updateEnergy(soModuleAccesser*, soKineticEnergy::AttributeFlag);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual unsigned long long getSumSpeed(const unsigned short&);
};
struct Local { u8 b8; u8 b9; u16 attributes; V2 vectors[5]; u32 sum[2]; Vec2f speed; };
extern "C" const f32 lbl_110_rodata_98;
extern "C" void fn_110_B860(V2*, const V2*);
extern "C" void fn_110_13E34(void* unused, void* self, soModuleAccesser* accesser) {
    Local local;
    KineticView* kinetic = reinterpret_cast<KineticView*>(&accesser->getKineticModule());
    local.attributes = 1;
    *reinterpret_cast<unsigned long long*>(local.sum) = kinetic->getSumSpeed(local.attributes);
    Vec2f::copy(local.speed, *reinterpret_cast<Vec2f*>(local.sum));
    kinetic->unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    f32 ffa7 = params->getParamFloat(accesser, 0xfa7, 0);
    f32 ffa9 = params->getParamFloat(accesser, 0xfa9, 0);
    f32 ffa6 = params->getParamFloat(accesser, 0xfa6, 0);
    f32 ffaa = params->getParamFloat(accesser, 0xfaa, 0);
    local.b9 = 0;
    local.vectors[4].x = local.speed.m_x; local.vectors[4].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x18), &local.vectors[4]);
    local.vectors[3].x = lbl_110_rodata_98; local.vectors[3].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x20), &local.vectors[3]);
    local.vectors[2].x = ffa7; local.vectors[2].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x30), &local.vectors[2]);
    local.vectors[1].x = ffa6; local.vectors[1].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x28), &local.vectors[1]);
    local.vectors[0].x = ffa6; local.vectors[0].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x38), &local.vectors[0]);
    *((u8*)self + 0x15) |= 0x80;
    local.b8 = 0;
    *(f32*)((char*)self + 0x58) = local.speed.m_y;
    *(f32*)((char*)self + 0x5c) = -ffa9;
    *(f32*)((char*)self + 0x60) = ffaa;
    *((u8*)self + 0x55) |= 0x80;
}