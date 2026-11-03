#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

struct CaptainFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct CaptainInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    CaptainFlags flags;
};

struct LaunchParam {
    float minScale;
    int workA;
    int workB;
    float rangeMin;
    float rangeMax;
};

extern "C" {
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
void fn_27_1D8370(void*, const CaptainInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
double sin(double);
double cos(double);
float randf__Fv();
}

static inline const LaunchParam* getLaunchParam(const StageObject* object)
{
    return *reinterpret_cast<const LaunchParam* const*>(reinterpret_cast<const char*>(object) + 0x1F7C);
}

extern "C" void fn_27_33029C(StageObject* object, int resource, int parameter,
    const Vec3f* position, int special, float facing, float strength, float scale, float power, float angle)
{
    CaptainInitialize initialize;
    initialize.resource = resource;
    initialize.team = 0xFFFF;
    initialize.teamOwner = 0xFFFF;
    initialize.teamAnother = 0xFFFF;
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

    object->m_moduleAccesser->getWorkManageModule().setInt(special, 0x10000007);
    object->m_moduleAccesser->getWorkManageModule().setInt(getLaunchParam(object)->workA, 0x10000005);
    object->m_moduleAccesser->getWorkManageModule().setInt(getLaunchParam(object)->workB, 0x10000006);
    object->m_moduleAccesser->getWorkManageModule().setFloat(scale, 0x11000001);
    object->m_moduleAccesser->getGroundModule().setOffsetY(getLaunchParam(object)->minScale, 0);
    object->m_moduleAccesser->getPostureModule().setScale(scale);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);

    soKineticEnergy* kinetic = object->m_moduleAccesser->getKineticModule().getEnergy(0);
    char* energy = static_cast<char*>(__dynamic_cast(kinetic, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1));

    const LaunchParam* param = getLaunchParam(object);
    power *= strength * (param->rangeMin + (param->rangeMax - param->rangeMin) * randf__Fv());

    float sinValue = (float)sin(angle);
    float vy = power * sinValue;
    float cosValue = (float)cos(angle);
    float vx = facing * (power * cosValue);

    Vec2f velocity(vx, vy);
    *reinterpret_cast<Vec2f*>(energy + 0x8) = velocity;

    object->updateNodeSRT();
}
