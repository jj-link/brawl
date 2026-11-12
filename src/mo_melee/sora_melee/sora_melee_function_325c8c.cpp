#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct Init {
    int resource, team, teamOwner, teamAnother, index, owner, reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
struct LaunchParam { int first; float angle; float power; };
extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
void fn_27_1D8370(void*, const Init*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
double sin(double);
double cos(double);
}
static inline const LaunchParam* getLaunchParam(const StageObject* object) {
    return *reinterpret_cast<const LaunchParam* const*>(reinterpret_cast<const char*>(object) + 0x1F90);
}
static inline void finish(StageObject* object, int workValue, float facing) {
    soModuleAccesser* acc = object->m_moduleAccesser;
    soWorkManageModule& work = acc->getWorkManageModule();
    work.setInt(getLaunchParam(object)->first, 0x10000003);
    work.setInt(getLaunchParam(object)->first, 0x10000004);
    soKineticEnergy* kinetic = acc->getKineticModule().getEnergy(0);
    char* energy = static_cast<char*>(__dynamic_cast(kinetic, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1));
    float angle = getLaunchParam(object)->angle;
    float power = getLaunchParam(object)->power;
    float vy = power * (float)sin(angle);
    float vx = facing * (power * (float)cos(angle));
    Vec2f velocity(vx, vy);
    *reinterpret_cast<Vec2f*>(energy + 0x8) = velocity;
    acc->getStatusModule().changeStatusForce(0, acc);
    acc->getWorkManageModule().setInt(workValue, 0x10000005);
}
extern "C" void fn_27_325C8C(StageObject* object, int resource, int team, const Vec3f* position,
    int parameter, int workValue, float facing) {
    Init init;
    init.resource = resource;
    init.team = team;
    init.teamOwner = team;
    init.teamAnother = team;
    init.index = -1;
    init.owner = -1;
    init.reserved0 = 0;
    init.reserved1 = 0;
    __memcpy(&init.position, position, sizeof(Vec3f));
    init.facing = facing;
    init.parameter = parameter;
    init.variant = 0;
    init.situation = 2;
    init.status = 0x80;
    init.reserved2 = 0;
    init.motion = 0x35f;
    init.reserved3 = 0;
    init.flags.first = 1;
    init.flags.second = 0;
    init.flags.third = 0;
    init.flags.fourth = 0;
    init.flags.fifth = 1;
    init.flags.sixth = 0;
    init.flags.seventh = 0;
    init.flags.eighth = 0;
    init.flags.ninth = 0;
    init.flags.tenth = 0;
    fn_27_1D8370(object, &init);
    finish(object, workValue, facing);
}