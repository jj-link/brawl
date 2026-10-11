#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>

extern "C" {
extern const float lbl_91_rodata_40;
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);
void fn_91_131E4(MarioMantleInitializeObject* object, int resource, int team, int parameter, int value) {
    MarioMantleInitializeVector position = { lbl_91_rodata_40, lbl_91_rodata_40, lbl_91_rodata_40 };
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
    initialize.facing = lbl_91_rodata_40;
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
    object->accesser->getLinkModule().setAttribute(3, static_cast<soLinkConnection::Attribute>(4), true);
    object->accesser->getLinkModule().setModelConstraintFlag(8);
    object->accesser->getWorkManageModule().setInt(value, 0x10000005);
}
void fn_91_13334(MarioMantleInitializeObject* object, float value) {
    object->accesser->getWorkManageModule().setFloat(value, 0x11000001);
}
}
