#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct LuigiInitializeObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
struct LuigiInitializeFlags {
    unsigned char first : 1;
    unsigned char second : 1;
    unsigned char third : 1;
    unsigned char fourth : 1;
    unsigned char fifth : 1;
    unsigned char sixth : 1;
    unsigned char seventh : 1;
    unsigned char eighth : 1;
    unsigned char ninth : 1;
    unsigned char tenth : 1;
    unsigned char reserved : 6;
};
struct LuigiInitializeParam {
    int resource;
    int team, teamOwner, teamAnother;
    int index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    LuigiInitializeFlags flags;
};

extern "C" {
extern const float lbl_99_rodata_60;
Vec3f* fn_99_C610(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const LuigiInitializeParam*);
void fn_99_103D4(LuigiInitializeObject* object, int resource, int team, int parameter, float facing) {
    Vec3f position;
    fn_99_C610(&position, lbl_99_rodata_60, lbl_99_rodata_60, lbl_99_rodata_60);
    LuigiInitializeParam initialize;
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
    initialize.flags.fifth = 0;
    fn_27_1D8370(object, &initialize);
    object->accesser->getWorkManageModule().onFlag(0x12000000);
    soWorkManageModule* work = &object->accesser->getWorkManageModule();
    work->setFloat(soValueAccesser::getConstantFloat(object->accesser, 0xfa0, 0), 0x11000001);
    soModuleAccesser* accesser = object->accesser;
    accesser->getStatusModule().changeStatusForce(0, accesser);
}
}
