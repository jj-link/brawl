#include <mo_fighter/ft_dedede/ft_dedede_projectile_initialize.h>
#include <so/so_module_accesser.h>

// ABI views of the projectile's externally owned variant and parameter tables.
struct DededeInitializeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct DededeInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    DededeInitializeFlags flags;
};
struct DededeVariant {
    unsigned char prefix[4];
    float damage;
    int parameter;
    unsigned char middle[0x2c];
    float gravity, terminalSpeed;
    unsigned char suffix[0x24];
    int groundedWork, groundedParameter;
};
struct DededeParameterTemporary { unsigned char storage[0x10]; };
struct DededeInitializeObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
    unsigned char middle[0x25e0];
    unsigned char* parameters;
    DededeVariant* variants;
};
struct DededeGravityEnergy {
    unsigned char prefix[8];
    float speed, acceleration, terminalSpeed;
};
// Narrow ABI view for the team interface absent from the shared module
// headers. Unused slots retain their offsets, not guessed APIs.
class DededeTeamModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(int);
};
extern "C" {
void fn_27_1D8370(void*, const DededeInitializeParam*);
void* fn_27_C7744(void*, void*, int);
void* fn_27_C77B0(void*, const void*);
void* fn_27_C7770(void*, short);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_117_data_A684[], lbl_117_data_36A8[];
extern const float lbl_117_rodata_110;
}

extern "C" void fn_117_1F2EC(DededeInitializeObject* object, unsigned int resource,
    unsigned int team, int parameter, const Vec3f* position, float facing, int kind, int grounded) {
    int owner;
    if (kind == 0) owner = 1;
    else owner = kind == 1 ? 2 : 3;
    object->accesser->getWorkManageModule().getParamAccesser();
    int variantParameter;
    if (grounded) variantParameter = object->variants[kind].groundedParameter;
    else variantParameter = object->variants[kind].parameter;
    DededeInitializeParam initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = owner;
    initialize.owner = owner;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.reserved2 = variantParameter;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved3 = 0;
    initialize.reserved4 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = grounded == 0;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    initialize.motion = 0x50;
    fn_27_1D8370(object, &initialize);
    object->accesser->getWorkManageModule().setInt(kind, 0x20000004);
    object->accesser->getWorkManageModule().setInt(kind, 0x10000005);
    DededeGravityEnergy* energy = static_cast<DededeGravityEnergy*>(__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(1), 0,
        lbl_117_data_A684, lbl_117_data_36A8, 1));
    energy->speed = lbl_117_rodata_110;
    energy->acceleration = -object->variants[kind].gravity;
    energy->terminalSpeed = -object->variants[kind].terminalSpeed;
    {
        DededeParameterTemporary temporary;
        fn_27_C7744(&temporary, *reinterpret_cast<void**>(object->parameters + 0x34 + kind * 4), 0x1c);
        fn_27_C77B0(reinterpret_cast<unsigned char*>(object) + 0x2734, &temporary);
        fn_27_C7770(&temporary, -1);
    }
    {
        DededeParameterTemporary temporary;
        fn_27_C7744(&temporary, *reinterpret_cast<void**>(object->parameters + 0x40 + kind * 4), 0x1c);
        fn_27_C77B0(reinterpret_cast<unsigned char*>(object) + 0x2760, &temporary);
        fn_27_C7770(&temporary, -1);
    }
    {
        DededeParameterTemporary temporary;
        fn_27_C7744(&temporary, *reinterpret_cast<void**>(object->parameters + 0x4c + kind * 4), 0x1c);
        fn_27_C77B0(reinterpret_cast<unsigned char*>(object) + 0x278c, &temporary);
        fn_27_C7770(&temporary, -1);
    }
    object->accesser->getDamageModule().addDamage(object->variants[kind].damage, 0);
    object->accesser->getDamageModule().setDamageLock(true);
    if (grounded) {
        object->accesser->getPostureModule().init(const_cast<Vec3f*>(position), facing);
        object->accesser->getWorkManageModule().onFlag(0x22000005);
        object->accesser->getStatusModule().changeStatusForce(0x15, object->accesser);
        object->accesser->getWorkManageModule().onFlag(0x2200000b);
        object->accesser->getWorkManageModule().setInt(object->variants[kind].groundedWork, 0x20000006);
    } else {
        static_cast<DededeTeamModule*>(object->accesser->m_enumerationStart->m_teamModule)->slot20(-1);
        object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
        object->accesser->getWorkManageModule().setInt(*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(&object->variants[kind]) + 0x18), 0x20000006);
        object->accesser->getAreaModule().setWhole(0);
    }
}
