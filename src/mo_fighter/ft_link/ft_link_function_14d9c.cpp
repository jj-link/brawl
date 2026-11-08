#pragma force_active on
#include <so/so_module_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
extern "C" {
extern const char lbl_93_data_7B28[], lbl_93_data_3BF8[], lbl_93_data_8DD0[], lbl_93_data_30FC[];
extern const float lbl_93_rodata_A0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_93_10424(Vec3f*, const Vec3f*, const Vec3f*);
Vec2f* fn_93_DAEC(Vec2f*, const Vec2f*);
float rsqrtf__Ff(float);
}
struct Access { char p[8]; void* object; char q[0xcc]; soModuleEnumeration* modules; };
struct Params { char pad[0x1c]; float a,b,c,d,limit; int pad2[2]; int node; };
extern "C" void fn_93_14D9C(void*, Access* a) {
    const float* constants = lbl_93_rodata_A0;
    char* casted = static_cast<char*>(__dynamic_cast(a->object, 0x3c, lbl_93_data_7B28, lbl_93_data_3BF8, 1));
    Params* params = *reinterpret_cast<Params**>(casted + 0x20e4);
    float angle = a->modules->m_workManageModule->getFloat(0x11000001);
    if (a->modules->m_linkModule->isLink(1) == true &&
        a->modules->m_workManageModule->isFlag(0x12000004) == false &&
        a->modules->m_workManageModule->getInt(0x20000000) > 0) {
        Vec3f parent = a->modules->m_linkModule->getParentModelNodeGlobalPosition(1, params->node, true);
        Vec3f diff;
        Vec3f pos = a->modules->m_postureModule->getPos();
        fn_93_10424(&diff, &parent, &pos);
        float theta = atan2(diff.m_y, diff.m_x);
        if (theta < constants[2]) theta += constants[3];
        else if (theta > constants[1]) theta -= constants[3];
        theta -= angle;
        if (theta < constants[2]) theta += constants[3];
        else if (theta > constants[1]) theta -= constants[3];
        if (theta > params->limit) theta = params->limit;
        else if (theta < -params->limit) theta = -params->limit;
        angle += theta;
        a->modules->m_workManageModule->setFloat(angle, 0x11000001);
        a->modules->m_workManageModule->decInt(0x20000000);
    }
    soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(a->modules->m_kineticModule->getEnergy(0), 0, lbl_93_data_8DD0, lbl_93_data_30FC, 1));
    Vec2f speed;
    __memcpy(&speed, &energy->getSpeed(), sizeof(speed));
    float sq = speed.m_x * speed.m_x + speed.m_y * speed.m_y;
    float len;
    if ((float)(double)nw4r::math::FAbs(sq) <= constants[4]) len = constants[0];
    else len = sq * rsqrtf__Ff(sq);
    float dist = params->a + len;
    if (dist > params->b) dist = params->b;
    fn_93_DAEC(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 8), &Vec2f(dist * (float)cos(angle), dist * (float)sin(angle)));
}