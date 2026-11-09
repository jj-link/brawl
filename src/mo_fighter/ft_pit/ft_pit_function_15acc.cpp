#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <st/stage.h>
#include <memory.h>
#pragma force_active on

struct Flags {
    unsigned char first:1, second:1, third:1, fourth:1;
    unsigned char fifth:1, sixth:1, seventh:1, eighth:1;
    unsigned char ninth:1, tenth:1, reserved:6;
};
struct Initialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
extern "C" {
extern Stage* lbl_27_bss_5668;
extern const float lbl_112_rodata_A8;
void fn_27_1D8370(void*, const Initialize*);
void fn_112_15ACC(StageObject* object, int resource, int team, int parameter, float value) {
    Vec3f position;
    lbl_27_bss_5668->getKirifudaPos(&position, 6);
    Initialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_112_rodata_A8;
    initialize.parameter = parameter;
    initialize.variant = 0;
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
    initialize.flags.fifth = 0;
    initialize.situation = 0;
    initialize.status = 0xff;
    fn_27_1D8370(object, &initialize);
    object->m_moduleAccesser->getWorkManageModule().setFloat(value, 0x11000001);
    Vec3f scale;
    lbl_27_bss_5668->getKirifudaScale(&scale, 6);
    object->m_moduleAccesser->getPostureModule().setScale(scale.m_x);
    if (lbl_27_bss_5668->getKirifudaModelType(6)) {
        object->m_moduleAccesser->getVisibilityModule().setStatusDefault(0, 1, true);
    }
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
}
}