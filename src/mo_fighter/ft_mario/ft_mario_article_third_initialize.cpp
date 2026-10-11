#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>

struct MarioThirdArticleInitializeObject : MarioMantleInitializeObject {
    unsigned char state[0x1f88 - sizeof(MarioMantleInitializeObject)];
    const int* workValue;
};

extern "C" {
extern const float lbl_91_rodata_90;
Vec3f* fn_91_E60C(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);
void fn_91_18D74(MarioThirdArticleInitializeObject* object, int resource, int team, int parameter, float facing) {
    Vec3f position;
    fn_91_E60C(&position, lbl_91_rodata_90, lbl_91_rodata_90, lbl_91_rodata_90);
    MarioMantleInitializeParam initialize;
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
    initialize.reserved2 = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved3 = 0;
    initialize.motion = 0x35f;
    initialize.reserved4 = 0;
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
    object->accesser->getWorkManageModule().setInt(*object->workValue, 0x10000005);
    soModuleAccesser* accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
}
}
