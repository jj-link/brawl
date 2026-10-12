#include <so/so_module_accesser.h>
#include <so/stageobject.h>

// The catch module and concrete fighter RTTI are not exposed by the shared headers.
class DededeCatchModule {
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
    virtual void setCatch(int, bool);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void releaseCatch(int);
};
struct DededeEvent {
    int kind;
    bool handled;
    unsigned char reserved[3];
    int node;
    unsigned int unused;
    float valueX, valueY;
};
struct DededeEventHandler {
    unsigned char reserved[0x60];
    soModuleAccesser* accesser;
    void handle(DededeEvent*, soModuleAccesser*, void*, int);
};
extern "C" {
float fn_27_8CAD0(void*);
void fn_27_1324D4(DededeEventHandler*, DededeEvent*, soModuleAccesser*, void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const unsigned char lbl_117_data_3650[], lbl_117_data_4148[], lbl_117_data_3254[];
int fn_117_20B0C(void*);
}
static inline DededeCatchModule* catchModule(soModuleAccesser* accesser) {
    return static_cast<DededeCatchModule*>(accesser->m_enumerationStart->m_catchModule);
}
inline void DededeEventHandler::handle(DededeEvent* event,
        soModuleAccesser* accesser, void* object, int eventType) {
    DededeEventHandler* self = this;
    soStatusModule* status = accesser->m_enumerationStart->m_statusModule;
    status->getStatusKind();
    switch (event->kind) {
    case 8:
        if (status->getStatusKind() == 0x112 || status->getStatusKind() == 0x117) {
            float scale = fn_27_8CAD0(object);
            if (scale <= accesser->getPostureModule().getScale()) {
                status->changeStatusRequest(0x119, self->accesser);
                event->node = self->accesser->getModelModule().getCorrectNodeId(0x12C);
                event->handled = true;
            }
            return;
        }
        break;
    case 20:
        status->changeStatusRequest(0x11A, self->accesser);
        break;
    case 9:
        if (status->getStatusKind() >= 0x11B && status->getStatusKind() <= 0x126) {
            catchModule(self->accesser)->releaseCatch(0);
            catchModule(self->accesser)->setCatch(0, true);
            if (accesser->getSituationModule().getKind() == 0)
                status->changeStatusRequest(0, self->accesser);
            else
                status->changeStatusRequest(0xE, self->accesser);
            return;
        }
        if (status->getStatusKind() == 0x119 || status->getStatusKind() == 0x11A)
            break;
        if (status->getStatusKind() == 0x128) {
            if (accesser->getWorkManageModule().isFlag(0x22000016)) {
                catchModule(accesser)->releaseCatch(0);
                catchModule(accesser)->setCatch(0, false);
            } else {
                catchModule(self->accesser)->releaseCatch(0);
                catchModule(self->accesser)->setCatch(0, true);
                if (accesser->getSituationModule().getKind() == 0)
                    status->changeStatusRequest(0, self->accesser);
                else
                    status->changeStatusRequest(0xE, self->accesser);
            }
            return;
        }
        break;
    case 24:
        accesser->getWorkManageModule().setFloat(event->valueX, 0x21000006);
        accesser->getWorkManageModule().setFloat(event->valueY, 0x21000007);
        accesser->getWorkManageModule().onFlag(0x22000017);
        break;
    case 60:
        if (eventType == 1) {
            StageObject* fighter = static_cast<StageObject*>(__dynamic_cast(
                object, 0x3C, lbl_117_data_3650, lbl_117_data_4148, 1));
            if (fighter->soGetSubKind() == 0x33) {
                void* dedede = __dynamic_cast(object, 0x3C,
                    lbl_117_data_3254, lbl_117_data_4148, 1);
                if (fn_117_20B0C(dedede))
                    self->accesser->getWorkManageModule().subInt(1, 0x10000042);
                else
                    self->accesser->getWorkManageModule().subInt(1, 0x10000040);
            }
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}

extern "C" void fn_117_94DC(DededeEventHandler* self, DededeEvent* event,
        soModuleAccesser* accesser, void* object, int eventType) {
    self->handle(event, accesser, object, eventType);
}
