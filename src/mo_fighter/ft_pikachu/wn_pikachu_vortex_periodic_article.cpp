#include <so/so_module_accesser.h>

// The common module enumeration leaves this manager opaque. Preserve the
// original dispatch slot; the preceding entries are not called here.
class VortexPeriodicArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
public:
    virtual void* generate(int article, int operation, bool persistent) = 0;
};
extern "C" int fn_98_14498();

extern "C" void fn_98_191D4(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    work->incInt(0x1000000b);
    const int elapsed = work->getInt(0x1000000b);
    if (elapsed >= fn_98_14498()) {
        if (work->getInt(0x10000007) >= 1) {
            VortexPeriodicArticleManager* manager = static_cast<VortexPeriodicArticleManager*>(
                accesser->m_enumerationStart->m_generateArticleManageModule);
            manager->generate(0, 0, false);
        }
        work->setInt(0, 0x1000000b);
    }
}
