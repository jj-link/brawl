#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <memory.h>
#pragma force_active on

struct SnakeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct SnakeInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    SnakeFlags flags;
};

extern "C" {
extern const float lbl_122_rodata_108;
Vec3f* fn_122_D580(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const SnakeInitialize*);
void fn_27_89544(void*, int);
void fn_27_894D4(void*, unsigned int);

void fn_122_1FA10(StageObject* object, int resource, int team, int parameter, float farg0) {
    Vec3f position;
    fn_122_D580(&position, lbl_122_rodata_108,
                lbl_122_rodata_108, lbl_122_rodata_108);

    SnakeInitialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_122_rodata_108;
    initialize.parameter = parameter;
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

    fn_27_1D8370(object, &initialize);

    object->m_moduleAccesser->getStatusModule().changeStatusForce(
        0, object->m_moduleAccesser);
    object->m_moduleAccesser->getWorkManageModule().setFloat(farg0, 0x11000001);
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 0);
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 1);
    fn_27_894D4(&object->m_moduleAccesser->getKineticModule(), 2);
    object->m_moduleAccesser->getGroundModule().setCalcLineMove(false, 0);
}
}
