#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_energy.h>
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
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
void fn_27_1D8370(void*, const LaunchParam*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

extern "C" void fn_27_368074(StageObject* object, int resource, int team, int parameter,
    const Vec3f* position, const Vec2f* speed, float facing)
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

    soKineticEnergy* kinetic = object->m_moduleAccesser->getKineticModule().getEnergy(0);
    char* energy = static_cast<char*>(__dynamic_cast(kinetic, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1));
    *reinterpret_cast<Vec2f*>(energy + 0x8) = *speed;

    int value = *reinterpret_cast<int*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(object) + 0x1fb0) + 0xc);
    object->m_moduleAccesser->getWorkManageModule().setInt(value, 0x10000005);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
}
