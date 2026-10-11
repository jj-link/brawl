#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>

// The shared enumeration leaves the article manager opaque. Retain the
// existing manager's virtual slots, exposing only the removal operation.
class NessArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
public:
    virtual void remove(int, int) = 0;
};

extern "C" void fn_101_11C34(void*, soModuleAccesser* accesser, int eventKind) {
    soLinkModule& link = accesser->getLinkModule();
    if (link.isLink(6)) {
        link.unlink(6);
    }
    static_cast<NessArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule)->remove(2, 0);
    if (eventKind == 16) {
        g_ftCommonDataAccesser.getData(static_cast<ftKind>(10));
    }
}

void operator delete(void*);

extern "C" void* fn_101_11CE0(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
