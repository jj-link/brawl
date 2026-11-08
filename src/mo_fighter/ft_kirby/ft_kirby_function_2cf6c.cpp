#include <types.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <mo_fighter/ft_dedede/ft_dedede_link_event.h>
#pragma force_active on

class StatusModule {
public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual bool changeStatusRequest(int status, soModuleAccesser* accesser);
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0A();
    virtual void f0B();
    virtual void f0C();
    virtual void f0D();
    virtual void f0E();
    virtual void f0F();
    virtual s32 getStatusKind();
};

struct Event {
    int kind;
};

struct KirbyLinkFighter {
    char pad0[0x60];
    soModuleAccesser* accesser;
};

static inline StatusModule* stat(soModuleAccesser* a) {
    return reinterpret_cast<StatusModule*>(a->m_enumerationStart->m_statusModule);
}

extern "C" void fn_96_2CF6C(KirbyLinkFighter* self, Event* event, soModuleAccesser* accesser, StageObject* object, int eventType) {
    switch (event->kind) {
    case 0x83A:
        if (stat(accesser)->getStatusKind() == 0) {
            stat(self->accesser)->changeStatusRequest(1, self->accesser);
        } else if (stat(accesser)->getStatusKind() == 1) {
            stat(self->accesser)->changeStatusRequest(2, self->accesser);
        } else if (stat(accesser)->getStatusKind() == 2) {
            stat(self->accesser)->changeStatusRequest(3, self->accesser);
        } else if (stat(accesser)->getStatusKind() == 3) {
            stat(self->accesser)->changeStatusRequest(4, self->accesser);
        } else if (stat(accesser)->getStatusKind() == 4) {
            stat(self->accesser)->changeStatusRequest(5, self->accesser);
        }
        break;
    }
    fn_27_1DB0F0(self, reinterpret_cast<soLinkEventArgs*>(event), accesser, object, eventType);
}