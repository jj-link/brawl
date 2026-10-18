#include <so/stageobject.h>
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
extern const float lbl_100_rodata_84;
Vec3f* fn_100_CC84(Vec3f*, float, float, float);
void fn_27_1D8370(void*, const CaptainInitialize*);
void fn_27_1DA698(void*, int, int, int);
}

extern "C" void fn_100_12F2C(
    StageObject* object, int resource, int team, int parameter,
    const Vec3f* position, int special, float facing, float scale)
{
    CaptainInitialize initialize;
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

    if (special)
        initialize.situation = 5;

    fn_27_1D8370(object, &initialize);

    soPostureModule* posture = &object->m_moduleAccesser->getPostureModule();
    if (special) {
        Vec3f rotation;
        posture->setRot(
            fn_100_CC84(&rotation, lbl_100_rodata_84,
                        lbl_100_rodata_84, lbl_100_rodata_84),
            0);
        object->updateNodeSRT();
        fn_27_1DA698(object, resource, 0, 0);
    } else {
        posture->setScale(scale);
    }
}
