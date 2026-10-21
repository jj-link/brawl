#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_8044[];
extern const unsigned char lbl_95_data_80C8[];
extern const float lbl_95_rodata_68;
extern const float lbl_95_rodata_6C;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_95_ABB4(Vec3f*, float, float, float);
}

extern "C" void fn_95_101B8(soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soModelModule* model = static_cast<soModelModule*>(__dynamic_cast(
        &accesser->getModelModule(), 8,
        lbl_95_data_8044, lbl_95_data_80C8, 1));

    if (accesser->getStatusModule().getStatusKind() != 0x11A) {
        accesser->getVisibilityModule().set(1, 0);
    }

    Vec3f scale;
    fn_95_ABB4(&scale, lbl_95_rodata_68,
              lbl_95_rodata_68, lbl_95_rodata_68);
    model->setNodeScale(2, &scale);
    model->setNodeRotateY(3, lbl_95_rodata_6C);
    model->setNodeRotateZ(2, lbl_95_rodata_6C);

    float lr = work->getFloat(0x21000008);
    if (lbl_95_rodata_6C != lr) {
        accesser->getPostureModule().setLr(lr);
    }

    float z = lbl_95_rodata_6C;
    work->setFloat(z, 0x21000008);
}
