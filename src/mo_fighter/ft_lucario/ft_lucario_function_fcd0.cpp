#include <types.h>
#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma scheduling off

extern "C" {
extern const float lbl_118_rodata_30[];
void fn_118_FA18(void*);
}

class TurnModuleLike {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual void reserved10();
    virtual void reserved14();
    virtual void reserved18();
    virtual int isTurning();
};

extern "C" void fn_118_FCD0(soModuleAccesser* accesser) {
    const float* constants = lbl_118_rodata_30;
    float angle = accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000005);
    float absAngle = (float)(double)nw4r::math::FAbs(angle);
    float diff = (float)(double)nw4r::math::FAbs(absAngle - constants[1]);
    float x;
    float y;
    float lr;

    if (diff > constants[9]) {
        if (absAngle < constants[1]) {
            x = constants[1] - angle;
            y = constants[1] + -angle;
            lr = constants[3];
        } else {
            if (angle > constants[0]) {
                x = constants[1] + -angle;
                y = -(angle - constants[1]);
            } else {
                x = -angle - constants[17];
                y = x;
            }
            lr = constants[3];
        }
    } else {
        x = constants[0];
        if (angle > x) {
            y = x;
            lr = constants[3];
        } else {
            x = constants[4];
            y = x;
            lr = constants[3];
        }
    }

    soModelModule* model = accesser->m_enumerationStart->m_modelModule;
    int node1 = model->getCorrectNodeId(0x12e);
    int node2 = model->getCorrectNodeId(0x12f);

    Vec3f rot1;
    rot1.m_x = constants[16] * x;
    rot1.m_y = constants[0];
    rot1.m_z = constants[0];
    model->setNodeRotate(node1, &rot1);

    Vec3f rot2;
    rot2.m_x = constants[0];
    rot2.m_y = constants[16] * y;
    rot2.m_z = constants[0];
    model->setNodeRotate(node2, &rot2);

    if (!reinterpret_cast<TurnModuleLike*>(accesser->m_enumerationStart->m_turnModule)->isTurning() &&
        constants[0] != lr) {
        accesser->m_enumerationStart->m_postureModule->setLr(lr);
        accesser->m_enumerationStart->m_postureModule->updateRotYLr();
    }

    fn_118_FA18(accesser);
}
