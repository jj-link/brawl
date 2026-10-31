#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
// The accessor stores the article-manager interface as an opaque pointer.
class DededeStatusArticles {
public:
    virtual void slot00();
    virtual void slot04();
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
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void remove(int kind, int target, bool flag);
};
}

// status outside [0, 8] -> tail-call the article-manager's slot 0x68 with (0, 1, true).
extern "C" void fn_117_1C8AC(void*, soModuleAccesser* accesser, int status) {
    switch (status) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return;
    default:
        return reinterpret_cast<DededeStatusArticles*>(
                   accesser->m_enumerationStart->m_effectModule)
            ->remove(0, 1, true);
    }
}
