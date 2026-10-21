#include <so/so_module_accesser.h>
#include <memory.h>
#pragma force_active on

class IceClimberLinkView {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual unsigned int isLink(int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual unsigned int isValidParentShape(unsigned int);
    virtual unsigned long long getParentShapeCenterPos(unsigned int);
};

extern "C" void fn_105_15658(void*, soModuleAccesser* accesser) {
    if (reinterpret_cast<IceClimberLinkView*>(accesser->m_enumerationStart->m_linkModule)->isLink(6) == 1 &&
        reinterpret_cast<IceClimberLinkView*>(accesser->m_enumerationStart->m_linkModule)->isValidParentShape(6) == 1) {
        Vec2f pos;
        unsigned long long bits = reinterpret_cast<IceClimberLinkView*>(
            accesser->m_enumerationStart->m_linkModule)->getParentShapeCenterPos(6);
        __memcpy(&pos, &bits, sizeof(pos));
        accesser->m_enumerationStart->m_groundModule->setShapeSafePos(&pos, 0);
    }
}
