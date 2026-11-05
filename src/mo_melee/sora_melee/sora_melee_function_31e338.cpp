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

extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_753C;
void fn_27_1D8370(void*, const CaptainInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_27_31E338(StageObject* object, int resource, int parameter, const Vec3f* position, const Vec2f* speed, float facing, float power)
{
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

    soKineticEnergy* energy = (soKineticEnergy*)__dynamic_cast(
        object->m_moduleAccesser->getKineticModule().getEnergy(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    *(Vec2f*)((char*)energy + 0x8) = *speed;
    *(Vec2f*)((char*)energy + 0x10) = Vec2f(lbl_27_rodata_753C, lbl_27_rodata_753C);
    *(Vec2f*)((char*)energy + 0x18) = *speed;
    *(Vec2f*)((char*)energy + 0x28) = *speed;
    *((unsigned char*)energy + 5) |= 0x80;

    object->m_moduleAccesser->getStatusModule().changeStatusRequest(0, object->m_moduleAccesser);

    Vec3f rot(-power, lbl_27_rodata_753C, lbl_27_rodata_753C);
    soPostureModule* posture = &object->m_moduleAccesser->getPostureModule();
    posture->setRot(&rot, 0);

    object->updateNodeSRT();
}
