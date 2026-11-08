#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

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

struct V2 {
    float x;
    float y;
};

struct Local {
    unsigned char flag;
    unsigned char pad;
    unsigned short attributes;
    V2 vectors[5];
    unsigned int sum[2];
    Vec2f speed;
};

extern "C" const float lbl_110_rodata_98;
extern "C" void fn_110_B860(V2*, const V2*);

extern "C" void fn_110_14624(
    void* unused, void* self, soModuleAccesser* accesser
) {
    Local local;
    KineticView* kinetic =
        reinterpret_cast<KineticView*>(&accesser->getKineticModule());

    local.attributes = 1;
    *reinterpret_cast<unsigned long long*>(local.sum) =
        kinetic->getSumSpeed(local.attributes);
    Vec2f::copy(local.speed, *reinterpret_cast<Vec2f*>(local.sum));
    kinetic->unableEnergyAll();

    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    float fbc = params->getParamFloat(accesser, 0xfbc, 0);
    float fa3 = params->getParamFloat(accesser, 0xfa3, 0);

    local.flag = 0;
    local.vectors[4].x = local.speed.m_x;
    local.vectors[4].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x18), &local.vectors[4]);

    local.vectors[3].x = lbl_110_rodata_98;
    local.vectors[3].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x20), &local.vectors[3]);

    local.vectors[2].x = fbc;
    local.vectors[2].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x30), &local.vectors[2]);

    local.vectors[1].x = fa3;
    local.vectors[1].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x28), &local.vectors[1]);

    local.vectors[0].x = fa3;
    local.vectors[0].y = lbl_110_rodata_98;
    fn_110_B860((V2*)((char*)self + 0x38), &local.vectors[0]);

    *((unsigned char*)self + 0x15) |= 0x80;
}
