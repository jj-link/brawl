#include <mt/mt_vector.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct SnakeOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_122_D564(Vec3f* dst, const Vec3f* src);
extern "C" void fn_27_492C(void* object);
extern "C" const float lbl_122_rodata_C;

inline void copyVec(Vec3f* dst, const Vec3f& src) { fn_122_D564(dst, &src); }

extern "C" void fn_122_D390(SnakeOwner* arg0) {
    int kind = arg0->accesser->getStatusModule().getStatusKind();
    switch (kind) {
    case 0x130:
    case 0x131:
    case 0x132: {
        soModuleAccesser* accesser = arg0->accesser;
        Vec3f scale;
        float s = accesser->getPostureModule().getScale();
        scale.m_x = scale.m_y = scale.m_z = s;
        Vec3f rot;
        Vec3f pos;
        copyVec(&pos, accesser->getPostureModule().getPos());
        copyVec(&rot, accesser->getPostureModule().getRot(0));
        accesser->getModelModule().setNodeSRT(0, &scale, &rot, &pos);
        float angle = soValueAccesser::getConstantFloat(arg0->accesser, 0xFAE, 0);
        Vec3f rotVec;
        rotVec.m_x = lbl_122_rodata_C;
        rotVec.m_y = angle;
        rotVec.m_z = lbl_122_rodata_C;
        rotVec.m_y += arg0->accesser->getWorkManageModule().getFloat(0x21000005);
        accesser->getModelModule().setNodeRotate(10, &rotVec);
        Vec3f transVec;
        transVec.m_x = arg0->accesser->getWorkManageModule().getFloat(0x21000004);
        transVec.m_y = lbl_122_rodata_C;
        transVec.m_z = lbl_122_rodata_C;
        accesser->getModelModule().setNodeTranslate(10, &transVec);
        return;
    }
    default:
        break;
    }
    fn_27_492C(arg0);
}
