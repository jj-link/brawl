#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace {
// Same slot layout as the ft_diddy kinetic view: getSumSpeed is at vtable offset 0x3C
// and takes the attribute by reference, returning two words in r3/r4.
class Fn115KineticSpeedView : public soNullable {
public:
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
    virtual Vec2f getSumSpeed(const unsigned short&);
};
}

extern "C" {
float fn_115_E59C(float value);
float fn_8003DDD0(const Vec2f* lhs, const Vec2f* rhs);
extern const float lbl_115_rodata_70[];
}

extern "C" void fn_115_10020(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_115_rodata_70;
    unsigned short attributes = 1;
    Vec2f speed;
    Vec2f::copy(speed, reinterpret_cast<Fn115KineticSpeedView*>(&accesser->getKineticModule())->getSumSpeed(attributes));

    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x127: {
        if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(0xFF), 0)) {
            Vec2f normal;
            Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(0xFF), 0));
            float dot = fn_8003DDD0(&speed, &normal);
            if (dot - constants[10] >= constants[4] * soValueAccesser::getConstantFloat(accesser, 0xFB5, 0)) {
                float scale = soValueAccesser::getConstantFloat(accesser, 0xFB8, 0);
                accesser->getWorkManageModule().setFloat(normal.m_x * scale, 0x21000007);
                accesser->getWorkManageModule().setFloat(normal.m_y * scale, 0x21000008);
                accesser->getStatusModule().changeStatusRequest(0x129, accesser);
            }
        }
        if (!accesser->getWorkManageModule().isFlag(0x22000014) && speed.m_y < constants[5]) {
            accesser->getWorkManageModule().onFlag(0x22000014);
        }
        if (accesser->getWorkManageModule().isFlag(0x22000016)) {
            if (fn_115_E59C(accesser->getWorkManageModule().getFloat(0x2100000D)) >= constants[11]) {
                accesser->getStatusModule().changeStatusRequest(0x12A, accesser);
            }
        }
        break;
    }
    case 0x12A:
        if (constants[6] == fn_115_E59C(accesser->getWorkManageModule().getFloat(0x2100000D))) {
            accesser->getStatusModule().changeStatusRequest(0x10, accesser);
        }
        break;
    }
}
