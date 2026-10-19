#include <so/so_module_accesser.h>
#pragma force_active on

// Module vtable ABI view. Slot names are byte offsets from the vtable pointer;
// the first virtual function sits at +0x08 because the vtable starts with two header words.
class FtPikminModuleView {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void setCatch(int, bool) = 0;                      // +0x2C
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void sendEventParents(int, soLinkEventArgs&) = 0;  // +0x44
    virtual int getStatusKind() = 0;                           // +0x48
};

struct FtPikminLinkEvent : soLinkEventArgs {
    FtPikminLinkEvent(int eventKind) : soLinkEventArgs(eventKind) {}
};

extern "C" void fn_113_25FB8(void*, soModuleAccesser* accesser, int kind) {
    bool flag;
    switch (kind) {
    case 0x22:
    case 0x23:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
        flag = true;
        break;
    default:
        flag = false;
        break;
    }

    if (!flag) {
        reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_catchModule)
            ->setCatch(0, false);

        if (reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_statusModule)
                ->getStatusKind() == 0x21 &&
            (kind == 6 || kind == 0)) {
            FtPikminLinkEvent event(0x456);
            reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_linkModule)
                ->sendEventParents(3, event);
        } else {
            switch (reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_statusModule)
                        ->getStatusKind()) {
            case 0x26:
            case 0x27:
            case 0x28:
            case 0x29:
                if (kind != 6 && kind != 0) {
                    FtPikminLinkEvent event(0x457);
                    reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_linkModule)
                        ->sendEventParents(3, event);
                }
                break;
            default: {
                FtPikminLinkEvent event(0x457);
                reinterpret_cast<FtPikminModuleView*>(accesser->m_enumerationStart->m_linkModule)
                    ->sendEventParents(3, event);
                break;
            }
            }
        }
    }
}
