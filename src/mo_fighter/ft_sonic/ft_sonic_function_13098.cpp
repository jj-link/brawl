#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <memory.h>
#pragma force_active on

struct SonicFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct SonicInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    SonicFlags flags;
};
struct SonicPosition { float x, y; };
extern "C" {
extern const float lbl_123_rodata_70;
Vec3f* fn_123_12FF0(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const SonicInitialize*);
void fn_27_89544(void*, int);
void fn_27_894D4(void*, unsigned int);

void fn_123_13098(StageObject* object, int resource, int team, int parameter,
                  float facing, SonicPosition* source, unsigned int option) {
    Vec3f position;
    fn_123_12FF0(&position, source->x, source->y, lbl_123_rodata_70);
    SonicInitialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
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
    fn_27_1D8370(object, &initialize);
    if (option == 1) {
        object->m_moduleAccesser->getWorkManageModule().onFlag(0x12000003);
    }
    object->m_moduleAccesser->getStatusModule().changeStatusForce(
        0, object->m_moduleAccesser);
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 0);
    fn_27_89544(&object->m_moduleAccesser->getKineticModule(), 1);
    fn_27_894D4(&object->m_moduleAccesser->getKineticModule(), 2);
    object->m_moduleAccesser->getGroundModule().setCalcLineMove(false, 0);
}
}