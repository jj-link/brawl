#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_119_rodata_1C;
extern const float lbl_119_rodata_20;
void fn_119_7C40(Vec3f*, const Vec3f&);
Vec3f fn_119_8E54(soModuleAccesser*);
float fn_119_7C5C(float);
void fn_119_12ED0(void*, Vec3f*, float, Vec3f*, Vec3f*, float, int);
}

extern "C" int fn_119_7980(void* self, soModuleAccesser* accesser) {
    float scale = accesser->getPostureModule().getLr();
    Vec3f start;
    Vec3f offset;
    offset.m_x = lbl_119_rodata_1C;
    offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfcd, 0);
    offset.m_z = soValueAccesser::getConstantFloat(accesser, 0xfcc, 0);
    fn_119_7C40(&start, accesser->getModelModule().getNodeGlobalPosition(0, &offset, false, false));
    Vec3f end = fn_119_8E54(accesser);
    float lr = accesser->getPostureModule().getScale();
    float work = accesser->getWorkManageModule().getFloat(0x2100000b);
    float x = lr * soValueAccesser::getConstantFloat(accesser, 0xfc3, 0);
    end.m_x += x * work;
    end.m_y += lr * soValueAccesser::getConstantFloat(accesser, 0xfc4, 0);
    Vec3f middle;
    middle.m_x = start.m_x + lbl_119_rodata_20 * (end.m_x - start.m_x);
    float high;
    float low = start.m_y;
    if (low > end.m_y) {
        high = low;
        low = end.m_y;
    } else {
        high = end.m_y;
    }
    float limit = soValueAccesser::getConstantFloat(accesser, 0xfca, 0);
    if (fn_119_7C5C(end.m_y - start.m_y) >= limit) {
        middle.m_y = high + soValueAccesser::getConstantFloat(accesser, 0xfcb, 0);
    } else {
        middle.m_y = low + soValueAccesser::getConstantFloat(accesser, 0xfca, 0);
        float other = soValueAccesser::getConstantFloat(accesser, 0xfcb, 0);
        if (fn_119_7C5C(high - middle.m_y) < other)
            middle.m_y = high + soValueAccesser::getConstantFloat(accesser, 0xfcb, 0);
    }
    middle.m_z = start.m_z;
    float value = soValueAccesser::getConstantFloat(accesser, 0xfce, 0);
    int id = soValueAccesser::getConstantInt(accesser, 0x5dc9, 0);
    fn_119_12ED0(self, &start, scale, &middle, &end, value, id);
    return 1;
}