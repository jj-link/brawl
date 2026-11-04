#include <so/so_module_accesser.h>
#pragma force_active on

class Class_8BE4 {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16CDC();
    virtual void fn_95_17478();
    virtual void fn_95_17474();
    virtual void fn_95_17470();
    virtual void fn_95_1746C();
    virtual void fn_95_17464();
    virtual void fn_95_174AC();
    virtual void fn_95_174A4();
    virtual void fn_95_1749C();
    virtual void fn_95_17494();
    virtual void fn_95_1748C();
    virtual void fn_95_17424();
    virtual void fn_95_17458();
    virtual void fn_95_1744C();
    virtual void fn_95_17444();
    virtual void fn_95_17438();
};
class Class_8DBC {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16C80();
    virtual void fn_95_17664();
    virtual void fn_95_1765C();
    virtual void fn_95_17654();
    virtual void fn_95_1764C();
    virtual void fn_95_17644();
    virtual void fn_95_1763C();
    virtual void fn_95_17634();
    virtual void fn_95_1762C();
    virtual void fn_95_17624();
    virtual void fn_95_1761C();
    virtual void fn_95_17614();
    virtual void fn_95_1760C();
    virtual void fn_95_175BC();
    virtual void fn_95_17604();
    virtual void fn_95_175F4();
};
class CatchModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C(int);
};
struct Event {
    int kind;
    bool handled;
    int node;
};
extern "C" void fn_27_1324D4(void*, Event*, soModuleAccesser*, void*, int);
extern "C" void fn_95_A278(void* self, Event* event, soModuleAccesser* accesser, void* object, int value) {
    soStatusModule* status = accesser->m_enumerationStart->m_statusModule;
    soModelModule* model = accesser->m_enumerationStart->m_modelModule;
    switch (event->kind) {
    case 8:
        if (status->getStatusKind() == 0x112) {
            event->node = model->getCorrectNodeId(0x12c);
            event->handled = true;
            static_cast<CatchModule*>(accesser->m_enumerationStart->m_catchModule)->slot1C(-1);
            status->changeStatusRequest(0x117, accesser);
            return;
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, value);
}
