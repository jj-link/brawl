#include <so/so_module_accesser.h>
#include <mt/mt_matrix.h>
#include <wn/weapon.h>
#include <math.h>
#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on

struct Flags {
    unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;
    unsigned char i:1,j:1,rest:6;
};
struct Init {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
struct Params {
    float x, y, z, v0c, v10, v14, v18, v1c, v20, v24, v28;
    int v2c, v30;
    float v34;
    int v38;
};
struct Obj {
    char pad[0x3c];
    void** vtable;
    char pad40[0x20];
    soModuleAccesser* accesser;
    char pad64[0x2510-0x64];
    Params* params;
};
extern "C" {
extern const float lbl_122_rodata_130[];
extern const unsigned char lbl_122_data_10750[], lbl_122_data_81AC[], lbl_122_data_E1EC[];
void fn_27_1D8370(void*, const Init*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_122_12CC4(Vec2f*, const Vec2f*);
Vec2f* fn_122_145AC(Vec2f*, float, float);
void fn_122_D564(Vec3f*, const Vec3f*);
Vec3f* fn_122_D580(Vec3f*, float, float, float);
void fn_8003ECA0(Matrix*, float, float, float);
void fn_8003E3BC(Matrix*, Vec3f*, Vec3f*);
}
extern "C" void fn_122_25FC8(Obj* object, int resource, int team, int parameter, const Vec3f* position, const Vec3f* angles) {
    Init init;
    const float* constants = lbl_122_rodata_130;
    init.resource = resource;
    init.team = team;
    init.teamOwner = team;
    init.teamAnother = team;
    init.index = -1;
    init.owner = -1;
    init.reserved0 = 0;
    init.reserved1 = 0;
    __memcpy(&init.position, position, sizeof(Vec3f));
    init.facing = constants[3];
    init.parameter = parameter;
    init.variant = 0;
    init.situation = 2;
    init.status = 0x80;
    init.reserved2 = 0;
    init.motion = 0x35f;
    init.reserved3 = 0;
    init.flags.a = 1;
    init.flags.b = 0;
    init.flags.c = 0;
    init.flags.d = 0;
    init.flags.e = 1;
    init.flags.f = 0;
    init.flags.g = 0;
    init.flags.h = 0;
    init.flags.i = 0;
    init.flags.j = 0;
    fn_27_1D8370(object, &init);
    object->accesser->getLinkModule().setAttribute(3, (soLinkConnection::Attribute)4, true);
    char* energy = (char*)__dynamic_cast(object->accesser->getKineticModule().getEnergy(2), 0, lbl_122_data_10750, lbl_122_data_81AC, 0);
    if (energy) {
        Vec2f a; a.m_x = object->params->x; a.m_y = constants[3];
        fn_122_12CC4((Vec2f*)(energy+8), &a);
        Vec2f b; b.m_x = object->params->y; b.m_y = constants[3];
        fn_122_12CC4((Vec2f*)(energy+0x10), &b);
        Vec2f c; c.m_x = object->params->z; c.m_y = constants[3];
        fn_122_12CC4((Vec2f*)(energy+0x18), &c);
        Vec2f d;
        fn_122_145AC(&d, object->params->v34, object->params->v34);
        fn_122_12CC4((Vec2f*)(energy+0x20), &d);
        Vec3f dir;
        fn_122_D580(&dir, constants[3], constants[3], constants[5]);
        Matrix matrix;
        fn_8003ECA0(&matrix, constants[7]*angles->m_x, constants[7]*angles->m_y, constants[7]*angles->m_z);
        fn_8003E3BC(&matrix, &dir, &dir);
        float x = dir.m_x;
        float y = dir.m_y;
        float angle = constants[8] * (float)atan2(y, x);
        *(float*)(energy+0x34) = angle;
        Vec3f rot; rot.m_x = -angle; rot.m_y = constants[9]; rot.m_z = constants[3];
        object->accesser->getPostureModule().setRot(&rot, 1);
        object->accesser->getWorkManageModule().setFloat(angle, 0x21000002);
    }
    char* gravity = (char*)__dynamic_cast(object->accesser->getKineticModule().getEnergy(1), 0, lbl_122_data_E1EC, lbl_122_data_81AC, 0);
    if (gravity) {
        float z = object->params->v18;
        Vec3f v; v.m_x = constants[3]; v.m_y = constants[3]; v.m_z = z;
        fn_122_D564((Vec3f*)(gravity+8), &v);
    }
    ((Weapon*)object)->updateNodeSRT();
    object->accesser->getWorkManageModule().setInt(object->params->v38, 0x10000005);
    object->accesser->getWorkManageModule().setFloat(object->params->v24, 0x11000002);
    object->accesser->getWorkManageModule().setFloat(object->params->v28, 0x11000003);
    object->accesser->getWorkManageModule().setInt(object->params->v2c, 0x20000000);
    object->accesser->getWorkManageModule().setInt(object->params->v30, 0x20000001);
    object->accesser->getStatusModule().changeStatusForce(0, object->accesser);
    object->accesser->getWorkManageModule().setFloat(object->params->v10, 0x21000000);
    object->accesser->getWorkManageModule().setFloat(object->params->v14, 0x21000001);
    object->accesser->getWorkManageModule().setFloat(object->params->z, 0x21000003);
    object->accesser->getWorkManageModule().setFloat(object->params->v0c, 0x21000004);
    object->accesser->getWorkManageModule().offFlag(0x12000003);
}