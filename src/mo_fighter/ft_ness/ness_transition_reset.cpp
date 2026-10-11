#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/model/so_model_module_simple.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>

struct NessTransitionVector { float x; float y; };
extern "C" const float lbl_101_rodata_58;

extern "C" float fn_101_129F0(const NessTransitionVector* vector) {
    return vector->x * vector->x + vector->y * vector->y;
}

extern "C" NessTransitionVector fn_101_12A08(const NessTransitionVector* vector, float scale) {
    NessTransitionVector result;
    result.x = vector->x * scale;
    result.y = vector->y * scale;
    return result;
}

extern "C" void fn_101_12A34(void*, soModuleAccesser* accesser, int eventKind) {
    accesser->getModelModule().setNodeRotateZ(5, lbl_101_rodata_58);
    soPostureModule& posture = accesser->getPostureModule();
    Vec3f rotation(lbl_101_rodata_58, lbl_101_rodata_58, lbl_101_rodata_58);
    posture.setRot(&rotation, 0);
    if (eventKind == 25) {
        ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
        // This common parameter block is not yet described by ftData.
        unsigned char* parameters = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(data) + 0x84);
        float value = *reinterpret_cast<float*>(parameters + 0x2C);
        if (value > lbl_101_rodata_58) {
            accesser->getWorkManageModule().setFloat(value, 0x11000000);
        }
    }
}

void operator delete(void*);
extern "C" void* fn_101_12B04(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
