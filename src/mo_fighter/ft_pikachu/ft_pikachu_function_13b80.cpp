#include <so/so_module_accesser.h>
#include <wn/weapon.h>
#pragma force_active on

struct PikachuFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct PikachuInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    PikachuFlags flags;
};

struct PikachuParams {
    int unk0;
    float unk4;
    float unk8;
};

struct PikachuOwner {
    unsigned char reserved[0x60];
    soModuleAccesser* accesser;
};

struct PikachuEnergy {
    unsigned char prefix[8];
    Vec2f speed;
};

extern "C" {
extern const float lbl_98_rodata_A0[];
extern const char lbl_98_data_8510[], lbl_98_data_24B0[];

void fn_27_1D8370(void*, const PikachuInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_98_F5B0(Vec3f*, float, float, float);
void fn_98_1472C(void*, int);
int fn_98_14854(void*, int);
void fn_98_14074(void*, int);

static inline soModuleAccesser* pikaGetAccesser(PikachuOwner* o) { return o->accesser; }
static inline soModuleAccesser& pikaGetAccesserRef(PikachuOwner* o) { return *o->accesser; }

void fn_98_13B80(PikachuOwner* object, int resource, int team, int parameter,
                 Vec3f* position, int arg6, int arg7)
{
    Weapon* weapon = reinterpret_cast<Weapon*>(object);
    PikachuInitialize init;
    init.resource = resource;
    init.team = team;
    init.teamOwner = team;
    init.teamAnother = team;
    init.index = -1;
    init.owner = -1;
    init.reserved0 = 0;
    init.reserved1 = 0;
    __memcpy(&init.position, position, sizeof(Vec3f));
    init.facing = 1.0f;
    init.parameter = parameter;
    init.variant = 0;
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
    init.situation = 3;
    init.status = 0xff;
    fn_27_1D8370(weapon, &init);

    soModuleAccesser& accesser = *pikaGetAccesser(object);
    soGroundModule& ground = accesser.getGroundModule();
    soWorkManageModule& work = accesser.getWorkManageModule();
    Vec2f safePos;
    safePos.m_x = position->m_x;
    safePos.m_y = position->m_y;
    ground.setShapeSafePos(&safePos, 0);
    weapon->setPosForce(position);
    weapon->updateNodeSRT();
    float scale = 1.0f;
    float unusedA = -1.0f;
    work.setFloat(scale, 0x11000004);
    soKineticModule& kinetic = accesser.getKineticModule();
    PikachuEnergy* energy = static_cast<PikachuEnergy*>(__dynamic_cast(
        kinetic.getEnergy(0), 0, lbl_98_data_8510, lbl_98_data_24B0, 1));
    PikachuParams** params =
        reinterpret_cast<PikachuParams**>((char*)object + 0x217c);
    Vec2f velocity(0.0f, (*params)->unk4 * scale);
    float unusedB = 20.0f;
    energy->speed.m_x = velocity.m_x;
    energy->speed.m_y = velocity.m_y;
    ground.modifyRhombus(3.0f * scale, -3.0f * scale, scale, 0);
    work.setInt((int)(*params)->unk8, 0x10000008);
    float y = position->m_y;
    float offset = y - (*params)->unk4 * scale;
    work.setFloat(y, 0x11000001);
    work.setFloat(offset, 0x11000002);
    fn_98_1472C(object, arg6);
    fn_98_14854(object, 0);
    work.offFlag(0x12000003);
    work.onFlag(0x12000000);
    accesser.getStatusModule().changeStatusForce(0, &accesser);
    fn_98_14074(object, 0);

    soEffectModule& effect = accesser.getEffectModule();
    unsigned int handle1 = 0;
    if (arg7 != 0) {
        Vec3f pos1;
        Vec3f rot1;
        handle1 = effect.reqFollow(
            static_cast<EfID>(0x80008), 0, fn_98_F5B0(&pos1, 0.0f, 0.0f, 0.0f), fn_98_F5B0(&rot1, 0.0f, 0.0f, 0.0f), 1.0f,
            false, 0, 0, -1);
    }

    Vec3f v44;
    Vec3f v38;
    Vec3f v2c;
    Vec3f v20;
    unsigned int handle2 = effect.req(
        static_cast<EfID>(0x80009), 2,
        fn_98_F5B0(&v44, 0.0f, 0.0f, 0.0f),
        fn_98_F5B0(&v38, 0.0f, 0.0f, 0.0f), 1.0f,
        fn_98_F5B0(&v2c, 0.0f, 0.0f, 0.0f),
        fn_98_F5B0(&v20, 0.0f, 0.0f, 0.0f), false, 0);
    work.setInt(handle1, 0x1000000A);
    work.setInt(handle2, 0x1000000B);
}
}
