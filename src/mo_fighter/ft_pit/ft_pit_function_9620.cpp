#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" void fn_27_12BAF8(void*, int);
extern "C" const float lbl_112_rodata_8;

struct ftPitOwner {
    char pad[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_112_9620(ftPitOwner* self, int arg1) {
    soWorkManageModule* work = self->accesser->m_enumerationStart->m_workManageModule;
    float value = static_cast<float>(soValueAccesser::getConstantInt(self->accesser, 0x5dc3, 0));
    work->setFloat(value, 0x11000013);
    self->accesser->m_enumerationStart->m_workManageModule->offFlag(0x1200003D);
    soWorkManageModule* work2 = self->accesser->m_enumerationStart->m_workManageModule;
    work2->setFloat(soValueAccesser::getConstantFloat(self->accesser, 0xfbb, 0), 0x11000014);
    self->accesser->m_enumerationStart->m_workManageModule->setFloat(lbl_112_rodata_8, 0x11000015);
    self->accesser->m_enumerationStart->m_workManageModule->setInt(-1, 0x10000041);
    fn_27_12BAF8(self, arg1);
}
