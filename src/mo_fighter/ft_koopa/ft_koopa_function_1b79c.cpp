#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" float fn_102_1B8F4(float, float);
extern "C" const float lbl_102_rodata_78[];

class KineticLike {
public:
    virtual bool isNull() const;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual Vec2f getSumSpeed(const short&);
};

extern "C" void fn_102_1B79C(StageObject* self) {
    const float* c = lbl_102_rodata_78 + 1;
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z = self->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    Vec3f position = self->m_moduleAccesser->getPostureModule().getPos();
    short flag = 1;
    Vec2f speed;
    Vec2f::copy(speed, reinterpret_cast<KineticLike*>(self->m_moduleAccesser->m_enumerationStart->m_kineticModule)->getSumSpeed(flag));
    float lr = self->m_moduleAccesser->m_enumerationStart->m_postureModule->getLr();
    Vec3f rotation;
    rotation.m_x = c[3] * -fn_102_1B8F4(speed.m_y, speed.m_x * lr);
    rotation.m_y = c[-1] == lr ? c[4] : c[5];
    rotation.m_z = c[1];
    self->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
}
