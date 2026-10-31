#include <so/stageobject.h>
#pragma force_active on

extern "C" Vec3f* fn_114_12B94(Vec3f*, float, float, float);

struct LucasLaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct LucasLaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LucasLaunchFlags flags;
    LucasLaunchParam(int resourceArg, int parameterArg, const float* data) {
    Vec3f zero;
    fn_114_12B94(&zero, data[2], data[2], data[2]);
    resource = resourceArg;
    team = 0xffff;
    teamOwner = 0xffff;
    teamAnother = 0xffff;
    index = -1;
    owner = -1;
    reserved0 = 0;
    reserved1 = 0;
    __memcpy(&position, &zero, sizeof(Vec3f));
    facing = data[0];
    parameter = parameterArg;
    variant = 0;
    situation = 2;
    status = 0x80;
    reserved2 = 0;
    motion = 0x35f;
    reserved3 = 0;
    flags.first = 1;
    flags.second = 0;
    flags.third = 0;
    flags.fourth = 0;
    flags.fifth = 1;
    flags.sixth = 0;
    flags.seventh = 0;
    flags.eighth = 0;
    flags.ninth = 0;
    flags.tenth = 0;
    }
};
extern "C" {
extern const char lbl_114_rodata_130[];
Vec3f* fn_114_12B94(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const LucasLaunchParam*);
}
inline void lucasEffect(soEffectModule* effect, u32 effectId, const float* data) {
    Vec3f rot, pos;
    effect->reqFollow((EfID)effectId, 0,
        fn_114_12B94(&pos, data[2], data[2], data[4]),
        fn_114_12B94(&rot, data[2], data[2], data[2]),
        data[5], false, 0, 0, -1);
}
extern "C" void fn_114_1BDFC(StageObject* object, int resource, int taskId, int parameter, int kind) {
    const float* data = reinterpret_cast<const float*>(lbl_114_rodata_130);
    LucasLaunchParam initialize(resource, parameter, data);
    fn_27_1D8370(object, &initialize);
    const soModuleEnumeration* modules = object->m_moduleAccesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soPostureModule* posture = modules->m_postureModule;
    soStatusModule* status = modules->m_statusModule;
    soLinkModule* link = modules->m_linkModule;
    if (link->link(5, taskId)) {
        Vec3f position = link->getParentModelNodeGlobalPosition(5, (u32)0, true);
        posture->setPos(&position);
        work->setFloat(position.m_x, 0x21000000);
        work->setFloat(position.m_y, 0x21000001);
        work->setFloat(position.m_x, 0x21000002);
        work->setFloat(position.m_y, 0x21000003);
        if (kind == 0) {
            object->m_moduleAccesser->getSoundModule().playStatusSE((SndID)0x144d, true, 0);
        }
        soEffectModule* effect = object->m_moduleAccesser->m_enumerationStart->m_effectModule;
        unsigned effectId;
        if (kind == 5) { effectId = 0x1b0007; } else { effectId = 0x1b0006; }
        lucasEffect(effect, effectId, data);
        object->updateNodeSRT();
        link->setAttribute(5, (soLinkConnection::Attribute)13, true);
    }
    status->changeStatusForce(0, object->m_moduleAccesser);
}
