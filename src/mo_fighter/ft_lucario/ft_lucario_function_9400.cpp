#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct LucarioEvent {
    int kind;
    bool handled;
    int node;
    unsigned char unknown0C[0xC];
    int value18;
};

class LucarioStatusModuleSlots {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual bool changeStatusRequest(int status, soModuleAccesser* moduleAccesser);
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
    virtual int getStatusKind();
};

struct LucarioModelPrefix {
    int prefix00;
    int prefix04;
};

class LucarioModelModuleSlots : public LucarioModelPrefix {
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
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual int getCorrectNodeId(unsigned int nodeId);
};

class LucarioWorkManageSlots {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int getInt(unsigned int index);
};

extern "C" void fn_27_1324D4(void*, LucarioEvent*, soModuleAccesser*, void*, int);

extern "C" void fn_118_9400(void* self, LucarioEvent* event, soModuleAccesser* accesser, void* object, int eventType) {
    LucarioStatusModuleSlots* status = reinterpret_cast<LucarioStatusModuleSlots*>(accesser->m_enumerationStart->m_statusModule);
    switch (event->kind) {
    case 8:
        if (status->getStatusKind() == 0x113) {
            event->node = reinterpret_cast<LucarioModelModuleSlots*>(accesser->m_enumerationStart->m_modelModule)->getCorrectNodeId(0x12C);
            event->handled = true;
            event->value18 = reinterpret_cast<LucarioWorkManageSlots*>(accesser->m_enumerationStart->m_workManageModule)->getInt(0x10000033);
            status->changeStatusRequest(0x11A, accesser);
            return;
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}
