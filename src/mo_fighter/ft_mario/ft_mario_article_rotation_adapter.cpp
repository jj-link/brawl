#include <so/so_module_accesser.h>

extern "C" {
void fn_91_14434(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* enumeration = accesser->m_enumerationStart;
    soModelModule* model = enumeration->m_modelModule;
    model->setNodeRotateX(5, -enumeration->m_workManageModule->getFloat(0x21000000));
}
void* fn_91_14494(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
}
