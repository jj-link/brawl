#include <so/so_module_accesser.h>
#include <wn/weapon.h>

extern "C" const float lbl_101_rodata_110[];
extern "C" Vec3f* fn_101_1303C(Vec3f*, float, float, float);

// Preserve the out-of-line vector constructor and full-expression lifetime
// used by activation and effect requests.
struct NessActivationVector : Vec3f {
    inline NessActivationVector() {}
    inline NessActivationVector(const float* constants) {
        fn_101_1303C(this, constants[2], constants[2], constants[2]);
    }
    inline Vec3f* zero(const float* constants) {
        return fn_101_1303C(this, constants[2], constants[2], constants[2]);
    }
    inline Vec3f* offset(const float* constants) {
        return fn_101_1303C(this, constants[2], constants[2], constants[4]);
    }
};

struct NessLinkedActivationDescriptor {
    unsigned int taskId;
    int identifier0, identifier1, identifier2;
    int ownerId, teamId;
    int field18, field1C;
    Vec3f position;
    float facing;
    int parameter, field34, situation, status, field40, motion, field48;
    u8 active : 1;
    u8 linked : 1;
    u8 field4C2 : 2;
    u8 field4C4 : 1;
    u8 field4C5 : 3;
    u8 field4D0 : 2;
    u8 reserved : 6;

    inline NessLinkedActivationDescriptor(unsigned int task, int value, const Vec3f& pos, const float* constants)
        : taskId(task), identifier0(0xffff), identifier1(0xffff), identifier2(0xffff),
          ownerId(-1), teamId(-1), field18(0), field1C(0), position(pos), facing(constants[0]),
          parameter(value), field34(0), situation(2), status(0x80), field40(0),
          motion(0x35f), field48(0), active(1), linked(0), field4C2(0), field4C4(1),
          field4C5(0), field4D0(0) {}
};

extern "C" {
void fn_27_1D8370(void*, const NessLinkedActivationDescriptor*);

void fn_101_1C220(Weapon* object, unsigned int taskId, int parentTaskId, int parameter, int kind) {
    const float* constants = lbl_101_rodata_110;
    NessLinkedActivationDescriptor descriptor(taskId, parameter,
        NessActivationVector(constants), constants);
    fn_27_1D8370(object, &descriptor);
    const soModuleEnumeration* modules = object->m_moduleAccesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soPostureModule* posture = modules->m_postureModule;
    soStatusModule* status = modules->m_statusModule;
    soLinkModule* link = modules->m_linkModule;
    if (link->link(5, parentTaskId)) {
        Vec3f position = link->getParentModelNodeGlobalPosition(5, static_cast<u32>(0), true);
        posture->setPos(&position);
        work->setFloat(position.m_x, 0x21000000);
        work->setFloat(position.m_y, 0x21000001);
        work->setFloat(position.m_x, 0x21000002);
        work->setFloat(position.m_y, 0x21000003);
        if (kind == 0) object->m_moduleAccesser->getSoundModule().playStatusSE(static_cast<SndID>(0xe7c), true, 0);
        soEffectModule* effect = object->m_moduleAccesser->m_enumerationStart->m_effectModule;
        int effectId = kind == 5 ? 0xb0004 : 0xb0003;
        effect->reqFollow(static_cast<EfID>(effectId), 0,
            NessActivationVector().offset(constants),
            NessActivationVector().zero(constants),
            constants[5], false, 0, 0, -1);
        object->updateNodeSRT();
        link->setAttribute(5, static_cast<soLinkConnection::Attribute>(13), true);
    }
    status->changeStatusForce(0, object->m_moduleAccesser);
}
}
