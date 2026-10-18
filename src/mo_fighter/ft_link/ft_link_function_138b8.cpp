#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

struct LinkObject : MarioMantleInitializeObject {
    unsigned char pad[0x20e4 - sizeof(MarioMantleInitializeObject)];
    const float* value;
};

extern "C" {
extern const float lbl_93_rodata_80;
extern const float lbl_93_rodata_78;

Vec3f* fn_93_AC0C(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);

void fn_93_138B8(LinkObject* object, int resource, int team, int parameter) {
    Vec3f position;
    fn_93_AC0C(&position, lbl_93_rodata_80, lbl_93_rodata_80, lbl_93_rodata_80);

    MarioMantleInitializeParam p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, &position, sizeof(position));
    p.facing = lbl_93_rodata_78;
    p.parameter = parameter;
    p.reserved2 = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved3 = 0;
    p.motion = 0x35f;
    p.reserved4 = 0;
    p.flags.first = 1;
    p.flags.second = 0;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(object, &p);

    soModuleAccesser* a = object->accesser;
    a->getStatusModule().changeStatusForce(0, a);
    object->accesser->getWorkManageModule().onFlag(0x12000000);
    object->accesser->getGroundModule().setOffsetY(*object->value, 0);
    a = object->accesser;
    a->getStatusModule().changeStatusForce(1, a);
}
}
