#include <so/so_module_accesser.h>
#pragma force_active on

class SamusArticleManager {
public:
    virtual void* slot08();
    virtual void* slot0C();
    virtual void* slot10();
    virtual void* slot14();
    virtual void* slot18();
    virtual void slot1C(int, int, int);
    virtual void* slot20();
    virtual void* slot24();
    virtual void* slot28();
    virtual void* slot2C();
    virtual void* slot30();
    virtual void* slot34();
    virtual void* slot38();
    virtual void* slot3C();
    virtual void* slot40();
    virtual void* slot44();
    virtual void* slot48();
    virtual void* slot4C();
    virtual void* slot50(int kind);
};

extern "C" void fn_94_1AA18(void*, soModuleAccesser* accesser) {
    SamusArticleManager* mgr = static_cast<SamusArticleManager*>(
        accesser->m_enumerationStart->m_generateArticleManageModule);
    void* article = mgr->slot50(3);
    if (article) {
        accesser->getWorkManageModule().setInt(0, 0x10000040);
        mgr->slot1C(3, 0, 1);
    }
}
