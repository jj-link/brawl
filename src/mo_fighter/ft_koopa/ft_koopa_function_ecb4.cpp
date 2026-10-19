#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

class FtKoopaCatchModule {
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
    virtual int slot15();
};

extern "C" int fn_102_ECB4(void* unk, soModuleAccesser* accesser) {
    if (accesser->m_enumerationStart->m_linkModule->isLink(0) == true) {
        return static_cast<FtKoopaCatchModule*>(accesser->m_enumerationStart->m_catchModule)
            ->slot15();
    }
    return 0;
}
