#include <so/so_module_accesser.h>

namespace {
// The accessor stores the article-manager interface as an opaque pointer.
class DededeStatusArticles {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void remove(int kind, int target);
};
}

extern "C" void fn_117_10044(void*, soModuleAccesser*);

extern "C" void fn_117_FC90(void* receiver, soModuleAccesser* accesser, int status) {
    if (status >= 0x137 || status < 0x12F) {
        if (accesser->getWorkManageModule().isFlag(0x22000015))
            fn_117_10044(receiver, accesser);
    }
    if (status >= 0x138 || status < 0x12F) {
        static_cast<DededeStatusArticles*>(
            accesser->m_enumerationStart->m_generateArticleManageModule)->remove(1, 0);
    }
}
