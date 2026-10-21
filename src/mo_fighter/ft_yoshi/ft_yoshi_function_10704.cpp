#pragma opt_propagation off
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_8044[], lbl_95_data_80C8[];
extern const float lbl_95_rodata_68[];
extern unsigned char g_ftCommonDataAccesser[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
}

extern "C" void fn_95_10704(soModuleAccesser* accesser) {
    const float* constants = lbl_95_rodata_68;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soModelModule* model = static_cast<soModelModule*>(__dynamic_cast(
        modules->m_modelModule, 8, lbl_95_data_8044, lbl_95_data_80C8, 1));

    getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 4);

    float angle = work->getFloat(0x21000005);
    if (angle < constants[1]) {
        angle += constants[4];
    }
    if (angle > constants[4]) {
        angle -= constants[4];
    }

    model->setNodeRotateX(3, constants[5] * angle);
    work->setFloat(angle, 0x21000005);
}
