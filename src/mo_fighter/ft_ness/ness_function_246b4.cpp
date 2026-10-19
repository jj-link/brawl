#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_101_data_7F90[], lbl_101_data_4330[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct NessStageLink {
    unsigned char pad[0x2168];
    float* value;
};

extern "C" void fn_101_246B4(void*, soModuleAccesser* accesser) {
    float* p = static_cast<NessStageLink*>(
        __dynamic_cast(accesser->m_stageObject, 0x3C, lbl_101_data_7F90, lbl_101_data_4330, 1))->value;
    accesser->getWorkManageModule().setFloat(*p, 0x21000002);
}
