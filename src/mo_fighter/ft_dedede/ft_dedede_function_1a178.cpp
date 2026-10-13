#include <so/stageobject.h>
#include <memory.h>

struct DededeLinkedInitializeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct DededeLinkedInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    DededeLinkedInitializeFlags flags;
};

extern "C" {
extern const float lbl_117_rodata_E0;
void fn_27_1D8370(void*, const DededeLinkedInitializeParam*);

void fn_117_1A178(StageObject* object, unsigned int taskId, int team, float facing) {
    Vec3f position;
    position.m_x = lbl_117_rodata_E0;
    position.m_y = lbl_117_rodata_E0;
    position.m_z = lbl_117_rodata_E0;
    DededeLinkedInitializeParam initialize;
    initialize.resource = taskId;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = facing;
    initialize.parameter = -1;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    initialize.flags.ninth = 1;
    fn_27_1D8370(object, &initialize);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    object->m_moduleAccesser->getLinkModule().setModelConstraintFlag(8);
}
}
