#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <math.h>

class MarioArticleKineticSpeedView {
public:
    virtual void nullableSlot();
    virtual void updateEnergySlot();
    virtual unsigned long long getSpeedBits();
};

extern "C" {
extern unsigned char lbl_91_data_99B8[];
extern unsigned char lbl_91_data_28FC[];
extern const float lbl_91_rodata_80;
extern const float lbl_91_rodata_84;
void* __dynamic_cast(void*, int, const void*, const void*, short);
void fn_91_16C80(void*, soModuleAccesser* accesser) {
    MarioArticleKineticSpeedView* energy = static_cast<MarioArticleKineticSpeedView*>(__dynamic_cast(
        accesser->m_enumerationStart->m_kineticModule->getEnergy(0), 0,
        lbl_91_data_99B8, lbl_91_data_28FC, static_cast<short>(1)));
    Vec2f speed;
    unsigned long long returnedSpeed = energy->getSpeedBits();
    __memcpy(&speed, &returnedSpeed, sizeof(speed));
    double x = speed.m_x;
    double y = speed.m_y;
    float angle = lbl_91_rodata_80 * static_cast<float>(atan2(y, x));
    Vec3f rotation;
    rotation.m_x = lbl_91_rodata_84;
    rotation.m_y = lbl_91_rodata_84;
    rotation.m_z = angle;
    accesser->m_enumerationStart->m_postureModule->setRot(&rotation, 0);
}
}
