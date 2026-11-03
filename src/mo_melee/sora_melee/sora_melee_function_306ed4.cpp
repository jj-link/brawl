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
struct Param { char pad[0x10]; float a, b; };
extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_656C;
void fn_27_1D8370(void*, const CaptainInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
extern "C" void fn_27_306ED4(StageObject* object, int resource, int parameter, const Vec3f* position, int special, float facing) {
    CaptainInitialize init;
    init.resource = resource;
    init.team = 0xffff;
    init.teamOwner = 0xffff;
    init.teamAnother = 0xffff;
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
    soWorkManageModule& work = object->m_moduleAccesser->getWorkManageModule();
    Vec2f speed(lbl_27_rodata_656C, lbl_27_rodata_656C);
    Vec2f zero(lbl_27_rodata_656C, lbl_27_rodata_656C);
    if (special) {
        work.onFlag(0x22000000);
        speed.m_x = (*(Param**)((char*)object + 0x17a0))->b * facing;
    } else {
        work.offFlag(0x22000000);
        speed.m_x = (*(Param**)((char*)object + 0x17a0))->a * facing;
    }
    soKineticModule& kinetic = object->m_moduleAccesser->getKineticModule();
    kinetic.changeKinetic(2, object->m_moduleAccesser);
    soKineticEnergy* energy = (soKineticEnergy*)__dynamic_cast(kinetic.getEnergy(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    soModuleAccesser* accessor = object->m_moduleAccesser;
    Vec3f rot(lbl_27_rodata_656C, lbl_27_rodata_656C, lbl_27_rodata_656C);
    energy->resetEnergy(0, &speed, &rot, accessor);
    *(Vec2f*)((char*)energy + 0x10) = zero;
    *(Vec2f*)((char*)energy + 0x28) = speed;
    *(Vec2f*)((char*)energy + 0x18) = speed;
    *((unsigned char*)energy + 5) |= 0x80;
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
}