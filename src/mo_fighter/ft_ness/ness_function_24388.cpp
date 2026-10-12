#include <so/so_module_accesser.h>

extern "C" {
extern const unsigned char lbl_101_data_7F90[], lbl_101_data_4330[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const float lbl_101_rodata_180[2] = {60.0f, 0.0f};
}

// Yoyo parameters are reached through the weapon's article-specific tail.
struct NessYoyoRotationParameters {
    float unused;
    float start;
    float end;
};
struct NessYoyoRotationWeaponView {
    unsigned char prefix[0x2168];
    const NessYoyoRotationParameters* parameters;
};

extern "C" void fn_101_24388(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
    soModelModule* model = accesser->m_enumerationStart->m_modelModule;
    const NessYoyoRotationParameters* parameters = static_cast<NessYoyoRotationWeaponView*>(
        __dynamic_cast(accesser->m_stageObject, 0x3c,
            lbl_101_data_7F90, lbl_101_data_4330, 1))->parameters;
    if (work->isFlag(0x22000004)) {
        Vec3f position = link->getParentModelNodeGlobalPosition(5,
            static_cast<u32>(work->getInt(0x20000001)), false);
        accesser->m_enumerationStart->m_postureModule->setPos(&position);
    }
    float angle = parameters->end - parameters->start;
    angle *= accesser->m_enumerationStart->m_motionModule->getFrame() / lbl_101_rodata_180[0];
    angle = parameters->end - angle;
    work->addFloat(angle, 0x21000001);
    work->setFloat(angle, 0x21000002);
    model->setNodeRotateX(2, work->getFloat(0x21000001));
}
