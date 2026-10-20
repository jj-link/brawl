#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct LaunchInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};

struct LaunchObject {
    char prefix[0x60];
    soModuleAccesser* accesser;
    char middle[0x1f5c];
    float* parameters;
};

class ReflectModule : public soNull, public soNullable {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void set(int);
};

extern "C" {
extern const float lbl_96_rodata_568;
extern const char lbl_96_data_CEF4[], lbl_96_data_5E00[];
void fn_27_1D8370(void*, const LaunchInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_B890(Vec2f*, const Vec2f*);
}

extern "C" void fn_96_27E3C(
    LaunchObject* object, int resource, int team, int parameter,
    const Vec3f* position, float facing, float scale, int value, int mode)
{
    LaunchInitialize initialize;
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

    ReflectModule* reflect = *(ReflectModule**)(
        (char*)object->accesser->m_enumerationStart + 0xbc);
    reflect->set(1);

    Vec2f speed;
    speed.m_x = lbl_96_rodata_568;
    speed.m_y = lbl_96_rodata_568;
    float finalScale = scale;

    if (mode == 0) {
        speed.m_x = object->parameters[0] * facing;
        speed.m_y = lbl_96_rodata_568;
        object->accesser->getWorkManageModule().setFloat(
            object->parameters[1], 0x21000000);
    } else if (mode == 1) {
        float cosine = cos(object->parameters[2]);
        speed.m_x = -facing * (object->parameters[3] * cosine);
        float sine = sin(object->parameters[2]);
        speed.m_y = object->parameters[3] * sine;
        object->accesser->getWorkManageModule().setFloat(
            object->parameters[4], 0x21000000);
    } else {
        speed.m_x = object->parameters[10] * facing;
        speed.m_y = lbl_96_rodata_568;
        finalScale = object->parameters[14];
    }

    object->accesser->getWorkManageModule().setInt(mode, 0x20000001);

    char* energy = (char*)__dynamic_cast(
        object->accesser->getKineticModule().getEnergy(0),
        0, lbl_96_data_CEF4, lbl_96_data_5E00, 1);
    fn_96_B890((Vec2f*)(energy + 8), &speed);

    Vec2f zero;
    zero.m_x = lbl_96_rodata_568;
    zero.m_y = lbl_96_rodata_568;
    fn_96_B890((Vec2f*)(energy + 0x20), &zero);

    object->accesser->getWorkManageModule().setFloat(scale, 0x21000001);
    object->accesser->getWorkManageModule().setInt(value, 0x20000000);
    object->accesser->getPostureModule().setScale(finalScale);

    if (mode == 2) {
        object->accesser->getGroundModule().modifyRhombus(
            object->parameters[15], object->parameters[16],
            object->parameters[17], 0);
        object->accesser->getStatusModule().changeStatusForce(
            1, object->accesser);
    } else {
        float up = object->parameters[6] * scale;
        float down = object->parameters[7] * scale;
        float width = object->parameters[8] * scale;
        object->accesser->getGroundModule().modifyRhombus(
            up, down, width, 0);
        object->accesser->getStatusModule().changeStatusForce(
            0, object->accesser);
    }

    object->accesser->getWorkManageModule().onFlag(0x12000000);
}
