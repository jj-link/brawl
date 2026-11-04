#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
extern const float lbl_27_rodata_1FD4;
extern void* g_ftCommonData;
float fn_27_195388(float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

static inline void setVector(Vec2f& v, float x, float y) {
    v.m_x = x;
    v.m_y = y;
}

static inline float commonFloat(int offset, int field) {
    return *(float*)((char*)*(void**)((char*)g_ftCommonData + offset) + field);
}

extern "C" void fn_27_161688(int, int, const Vec2f*, soModuleAccesser* accesser) {
    void* p = soValueAccesser::getConstantIndefinite(accesser, 0xA80A, 0);
    Vec2f speed;
    speed.m_x = *(float*)((char*)p + 8) * accesser->getControllerModule().getStickX();
    int index = accesser->getWorkManageModule().getInt(0x10000001);
    speed.m_y = *(float*)((char*)*(float**)((char*)p + 0x10) + (index << 2) - 8);
    Vec2f mul(lbl_27_rodata_1FD4, lbl_27_rodata_1FD4);
    if (accesser->getParamCustomizeModule().isCustomize(0)) {
        float f = commonFloat(0x30, 0x1C);
        mul.m_y *= fn_27_195388(mul.m_y, accesser->getPostureModule().getBaseScale(), f);
    } else if (accesser->getParamCustomizeModule().isCustomize(1)) {
        float f = commonFloat(0x34, 0x1C);
        mul.m_y *= fn_27_195388(mul.m_y, accesser->getPostureModule().getBaseScale(), f);
    }
    if (accesser->getParamCustomizeModule().isCustomize(2)) {
        float* data = *(float**)((char*)g_ftCommonData + 0x38);
        mul.m_x *= data[5];
        mul.m_y *= data[6];
    }
    speed.m_x *= mul.m_x;
    speed.m_y *= mul.m_y;
    Vec2f motion;
    Vec2f gravity;
    Vec3f zero2;
    Vec3f zero1(lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0);
    gravity.m_x = lbl_27_rodata_1FC0;
    gravity.m_y = speed.m_y;
    fn_27_89D08(1, accesser, 0, &gravity, &zero1);
    zero2.m_x = lbl_27_rodata_1FC0;
    zero2.m_y = lbl_27_rodata_1FC0;
    zero2.m_z = lbl_27_rodata_1FC0;
    setVector(motion, speed.m_x, lbl_27_rodata_1FC0);
    fn_27_89D08(2, accesser, 4, &motion, &zero2);
}
