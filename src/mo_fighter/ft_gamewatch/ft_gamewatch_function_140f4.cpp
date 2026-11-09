#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" unsigned int fn_107_140F4(void*, soModuleAccesser* accesser, Vec3f*, Vec2f* result) {
    Vec3f point = accesser->getModelModule().getNodeGlobalPosition(14, false);
    float areaId;
    if (accesser->getAreaModule().getEnviromentElementChecker()->testWater(
            reinterpret_cast<Vec2f*>(&point), reinterpret_cast<int*>(&areaId))) {
        float x;
        float y = areaId;
        x = point.m_x;
        result->m_x = x;
        result->m_y = y;
        return 1;
    }
    return 0;
}
