#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" void fn_110_16990(void*, soModuleAccesser* accesser) {
    soWorkManageModule& w = accesser->getWorkManageModule();
    soModelModule& m = accesser->getModelModule();
    float v = -m.getNodeGlobalRotation(8, false).m_x;
    w.setFloat(v, 0x21000000);
    w.setFloat(v, 0x21000001);
    w.setFloat(v, 0x21000002);
    w.setFloat(v, 0x21000003);
}
