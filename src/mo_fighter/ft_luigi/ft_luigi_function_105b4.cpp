#include <so/so_module_accesser.h>

extern "C" {
void fn_27_492C(void* object);
extern const float lbl_99_rodata_60;

// Apply the positive work-variable scale uniformly to the root model node.
void fn_99_105B4(void* object) {
    fn_27_492C(object);
    soModuleAccesser* accesser = *reinterpret_cast<soModuleAccesser**>(
        static_cast<unsigned char*>(object) + 0x60);
    float value = accesser->getWorkManageModule().getFloat(0x11000001);
    Vec3f scale;
    scale.m_x = scale.m_y = scale.m_z = value;
    if (scale.m_x > lbl_99_rodata_60) {
        accesser = *reinterpret_cast<soModuleAccesser**>(
            static_cast<unsigned char*>(object) + 0x60);
        accesser->getModelModule().setNodeScale(1, &scale);
    }
}
}
