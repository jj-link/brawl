#include <so/so_module_accesser.h>
#pragma force_active on

class ftCaptainCatchModule {
public:
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(soModuleAccesser* accesser);
};

extern "C" void fn_100_DCC4(void*, soModuleAccesser* accesser) {
    static_cast<ftCaptainCatchModule*>(accesser->m_enumerationStart->m_catchModule)->slot15(accesser);
}
