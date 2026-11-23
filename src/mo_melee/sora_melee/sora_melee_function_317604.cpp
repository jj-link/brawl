#include <so/stageobject.h>
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

struct Params {
    char pad[0x38];
    float a, b;
    char pad2[0x18];
    float c;
};

extern int lbl_27_data_84258;
extern int lbl_27_data_2E60;

extern "C" void fn_27_1D8370(void*, const LaunchParam*);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void fn_27_31A014(void*, unsigned);

extern "C" void fn_27_317604(
    StageObject* object, int resource, int team, int parameter,
    const Vec3f* position, int heap, float facing, float extra)
{
    float leading = 1.0f, ten = 10.0f, twenty = 20.0f;
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

    object->m_moduleAccesser->getLinkModule().setAttribute(
        3, (soLinkConnection::Attribute)4, true);

    soControllerModule& controller =
        object->m_moduleAccesser->getControllerModule();
    controller.update(object->getInput(), false);

    soWorkManageModule& work =
        object->m_moduleAccesser->getWorkManageModule();
    work.onFlag(0x12000000);

    Params* p = *(Params**)((char*)object + 0x4870);
    work.setFloat(p->c, 0x11000001);
    work.setFloat(0.0f, 0x11000004);
    work.setFloat(0.0f, 0x11000005);
    work.setFloat(0.0f, 0x11000006);
    work.setFloat(0.0f, 0x11000007);

    work.offFlag(0x12000003);
    work.offFlag(0x12000004);
    work.offFlag(0x12000005);
    work.offFlag(0x12000006);
    work.offFlag(0x12000007);
    work.offFlag(0x12000008);
    work.offFlag(0x12000009);
    work.offFlag(0x1200000a);
    work.offFlag(0x1200000b);

    work.setInt(parameter, 0x10000005);
    work.setFloat(0.0f, 0x21000000);
    work.setFloat(0.0f, 0x21000001);
    work.setFloat(0.0f, 0x21000002);
    work.setFloat(0.0f, 0x21000003);
    work.setFloat(0.0f, 0x21000004);
    work.setFloat(0.0f, 0x21000005);
    work.setFloat(0.0f, 0x21000006);

    float negative = -1.0f;
    p = *(Params**)((char*)object + 0x4870);
    work.setInt(
        (int)(60.0f * p->a - (float(1.0) + extra) * p->b),
        0x10000006);

    soGroundModule* ground = &object->m_moduleAccesser->getGroundModule();
    ground->constructGrCollision(team, 0, (Heaps::HeapType)heap, 1, 0, 0);
    ground = (soGroundModule*)__dynamic_cast(
        &object->m_moduleAccesser->getGroundModule(), 8,
        &lbl_27_data_84258, &lbl_27_data_2E60, 1);
    fn_27_31A014(ground, 1);
    ground->setGrCollisionMode(true);
    ground->setEventToGround(true, 0);
}
