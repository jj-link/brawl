#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" void fn_27_135EB4(void*, soModuleAccesser*, void*, int, int);

extern "C" void fn_92_8FF0(void* self, soModuleAccesser* accesser, void* sender, int arg4, int arg5) {
    int kind = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    if (kind >= 0x120 && kind <= 0x129) {
        accesser->m_enumerationStart->m_statusModule->changeStatusRequest(-1, accesser);
    }
    fn_27_135EB4(self, accesser, sender, arg4, arg5);
}
