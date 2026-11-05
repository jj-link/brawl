#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct LaunchParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};

extern "C" {
void fn_27_1D8370(void*, const LaunchParam*);
}

extern "C" void fn_27_34B9BC(StageObject* object, int resource, int team, int parameter, const Vec3f* position, int reserved2, float facing)
{
    LaunchParam initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 0;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    initialize.reserved2 = reserved2;
    initialize.situation = 2;

    fn_27_1D8370(object, &initialize);
    object->m_moduleAccesser->getWorkManageModule().setInt(-1, 0x10000005);
    object->m_moduleAccesser->getWorkManageModule().setInt(
        soValueAccesser::getConstantInt(object->m_moduleAccesser, 0x5dc1, 0), 0x10000006);
    object->m_moduleAccesser->getWorkManageModule().offFlag(0x12000003);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    object->m_moduleAccesser->getLinkModule().setAttribute(3, (soLinkConnection::Attribute)0xd, true);
}
