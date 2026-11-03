#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct Speed { float x, y; };
class KineticView {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual Speed getSumSpeed(const short&);
};
extern "C" {
extern const char lbl_92_data_6480[], lbl_92_data_639C[], lbl_92_data_1874[];
extern const float lbl_92_rodata_18;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_92_BA0C(Vec2f*, const Vec2f*);
Vec3f* fn_92_D29C(Vec3f*, float, float, float);
}
extern "C" void fn_92_CFC0(void*, soModuleAccesser* accesser) {
    soSituationModule* situation = &accesser->getSituationModule();
    soKineticModule* kinetic = &accesser->getKineticModule();
    char* params = *(char**)((char*)g_ftCommonDataAccesser.getData((ftKind)1) + 0x84);
    short flag = 1;
    short mask = flag;
    Speed copied;
    Speed sum = ((KineticView*)kinetic)->getSumSpeed(mask);
    __memcpy(&copied, &sum, sizeof(copied));
    kinetic->changeKinetic(0x32, accesser);
    soKineticEnergy* stop = (soKineticEnergy*)__dynamic_cast(kinetic->getEnergy(2), 0, lbl_92_data_6480, lbl_92_data_1874, flag);
    soKineticEnergy* gravity = (soKineticEnergy*)__dynamic_cast(kinetic->getEnergy(1), 0, lbl_92_data_639C, lbl_92_data_1874, flag);
    if (situation->getKind() == 0) {
        Vec2f speed; speed.m_x = lbl_92_rodata_18; speed.m_y = lbl_92_rodata_18;
        Vec3f pos;
        stop->resetEnergy(5, &speed, fn_92_D29C(&pos, lbl_92_rodata_18, lbl_92_rodata_18, lbl_92_rodata_18), accesser);
        *(float*)((char*)stop + 0x3c) = *(float*)(params + 0x14);
        Vec2f a; a.m_x = *(float*)(params + 0xc); a.m_y = lbl_92_rodata_18;
        fn_92_BA0C((Vec2f*)((char*)stop + 0x18), &a);
        Vec2f b; b.m_x = *(float*)(params + 0xc); b.m_y = lbl_92_rodata_18;
        fn_92_BA0C((Vec2f*)((char*)stop + 0x28), &b);
    } else {
        Vec2f speed; speed.m_x = lbl_92_rodata_18; speed.m_y = lbl_92_rodata_18;
        Vec3f pos;
        stop->resetEnergy(0, &speed, fn_92_D29C(&pos, lbl_92_rodata_18, lbl_92_rodata_18, lbl_92_rodata_18), accesser);
        *(float*)((char*)stop + 0x3c) = *(float*)(params + 0x18);
        Vec2f a; a.m_x = *(float*)(params + 0x10); a.m_y = lbl_92_rodata_18;
        fn_92_BA0C((Vec2f*)((char*)stop + 0x18), &a);
        Vec2f b; b.m_x = *(float*)(params + 0x10); b.m_y = lbl_92_rodata_18;
        fn_92_BA0C((Vec2f*)((char*)stop + 0x28), &b);
        float gravitySpeed = *(float*)(params + 4);
        Vec2f c; c.m_x = lbl_92_rodata_18; c.m_y = gravitySpeed;
        Vec3f pos2;
        gravity->resetEnergy(0, &c, fn_92_D29C(&pos2, lbl_92_rodata_18, lbl_92_rodata_18, lbl_92_rodata_18), accesser);
        *(float*)((char*)gravity + 0xc) = *(float*)(params + 4);
        *(float*)((char*)gravity + 0x10) = *(float*)(params + 8) * -soValueAccesser::getConstantFloat(accesser, 0xbcf, 0);
        ((unsigned char*)gravity)[5] |= 0x80;
    }
    Vec2f finalSpeed; finalSpeed.m_x = copied.x; finalSpeed.m_y = lbl_92_rodata_18;
    fn_92_BA0C((Vec2f*)((char*)stop + 8), &finalSpeed);
    *(float*)((char*)stop + 0x40) = lbl_92_rodata_18;
    ((unsigned char*)stop)[5] |= 0x80;
}