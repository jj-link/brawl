#include <so/so_module_accesser.h>
#pragma force_active on

struct Status {
    virtual void a() = 0;
    virtual void b() = 0;
    virtual void c() = 0;
    virtual void chg(int, soModuleAccesser*) = 0;
};

extern "C" void fn_104_E908(void* self, soModuleAccesser* a) {
    const soModuleEnumeration* e = a->m_enumerationStart;
    soWorkManageModule* w = e->m_workManageModule;
    Status* s = (Status*)e->m_statusModule;
    if (w->isFlag(0x22000012)) {
        w->offFlag(0x22000012);
        s->chg(0x11a, a);
    }
}
