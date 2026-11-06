#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_100_data_18F8[], lbl_100_data_21AC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_100_E184(Vec3f*, const Vec3f*);
struct CaptainEventArgs {
    int id;
    unsigned char flag;
    int value;
    unsigned char rest[0x1c];
};
void fn_100_FB5C(soModuleAccesser*, CaptainEventArgs*);
}

extern "C" void fn_100_E258(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soPostureModule* posture = accesser->m_enumerationStart->m_postureModule;
    soSlowModule* slow = accesser->m_enumerationStart->m_slowModule;
    __dynamic_cast(accesser->m_stageObject, 0x3c, lbl_100_data_18F8, lbl_100_data_21AC, 1);
    Vec3f position;
    Vec3f initial = posture->getPos();
    fn_100_E184(&position, &initial);
    float lr = posture->getLr();
    work->setFloat(position.m_x, 0x21000004);
    work->setFloat(position.m_y, 0x21000005);
    work->setFloat(lr, 0x21000006);
    slow->clearWhole();
    slow->setWhole(4, 0);
    CaptainEventArgs args;
    args.id = 0x44f;
    args.flag = 0;
    args.value = 9;
    fn_100_FB5C(accesser, &args);
}