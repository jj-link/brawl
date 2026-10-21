#include <so/so_module_accesser.h>
#pragma force_active on

class Capture {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void release(int);
};

extern "C" void fn_27_1834F8(void*, soModuleAccesser* accesser) {
    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
    if (link->isLink(0)) {
        Vec2f pos;
        Vec2f::copy(pos, link->getParentShapeCenterPos(0));
        ((Capture*)accesser->m_enumerationStart->m_captureModule)->release(0);
        accesser->m_enumerationStart->m_groundModule->setShapeSafePos(&pos, 0);
    }
}
