#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <so/link/so_link_event_presenter.h>

#pragma force_active on

class PikminCatchModule {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(bool, bool);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(int);
};

struct PikminFighter {
    unsigned char padding[0x60];
    soModuleAccesser* accesser;
};

struct PikminLinkEvent : soLinkEventArgs {
    unsigned int node;
};

extern "C" void fn_113_1ADC8(PikminFighter*, int);
extern "C" void fn_113_1B02C(PikminFighter*);
extern "C" void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);

extern "C" void fn_113_19544(PikminFighter* self, PikminLinkEvent* event,
                             soModuleAccesser* accesser, StageObject* object,
                             int value) {
    switch (event->m_eventKind) {
    case 8:
        if (self->accesser->getStatusModule().getStatusKind() != 0x21) {
            event->_0x4 = false;
            return;
        }
        self->accesser->getStatusModule().changeStatusRequest(0x22, self->accesser);
        event->node = self->accesser->getModelModule().getCorrectNodeId(13);
        event->_0x4 = true;
        return;

    case 9:
        ((PikminCatchModule*)self->accesser->m_enumerationStart->m_catchModule)->f14(0);
        if (!self->accesser->getGroundModule().isTouch((grCollStatus::TouchMask)8, 0)) {
            self->accesser->getStatusModule().changeStatusRequest(10, self->accesser);
        } else if (self->accesser->getStatusModule().getStatusKind() == 0x22 ||
                   self->accesser->getStatusModule().getStatusKind() == 0x23 ||
                   self->accesser->getStatusModule().getStatusKind() == 0x24 ||
                   self->accesser->getStatusModule().getStatusKind() == 0x25) {
            self->accesser->getStatusModule().changeStatusRequest(0x24, self->accesser);
        }
        return;

    case 0x3d:
        if (value == 3) {
            if (object->soGetKind() == 2 && object->soGetSubKind() == 0x90) {
                self->accesser->getWorkManageModule().onFlag(0x12000004);
                fn_113_1ADC8(self, 8);
            } else if (self->accesser->getStatusModule().getStatusKind() == 0x17 &&
                       !self->accesser->getWorkManageModule().isFlag(0x22000000)) {
                self->accesser->getStatusModule().changeStatusRequest(0x18, self->accesser);
            }
        }
        break;

    case 2:
    case 0x38:
        if (value == 3 && self->accesser->getStatusModule().getStatusKind() == 0x17)
            self->accesser->getStatusModule().changeStatusRequest(0x18, self->accesser);
        break;

    case 0x37:
        if (value == 3 && self->accesser->getLinkModule().isModelConstraint() == 1)
            self->accesser->getVisibilityModule().setWhole(
                reinterpret_cast<unsigned char*>(event)[5]);
        break;
    }

    if (object->soGetKind() == 0 && object->soGetSubKind() == 0x19 && value == 1) {
        switch (event->m_eventKind) {
        case 0x457:
            ((PikminCatchModule*)self->accesser->m_enumerationStart->m_catchModule)->f9(false, false);
            if (!self->accesser->getGroundModule().isTouch((grCollStatus::TouchMask)8, 0)) {
                self->accesser->getStatusModule().changeStatusRequest(10, self->accesser);
            } else if (self->accesser->getStatusModule().getStatusKind() == 0x22 ||
                       self->accesser->getStatusModule().getStatusKind() == 0x23 ||
                       self->accesser->getStatusModule().getStatusKind() == 0x24 ||
                       self->accesser->getStatusModule().getStatusKind() == 0x25) {
                self->accesser->getStatusModule().changeStatusRequest(0x24, self->accesser);
            }
            break;

        case 2: {
            int status = self->accesser->getStatusModule().getStatusKind();
            bool excluded;
            switch (status) {
            case 0x1e:
            case 0x1f:
            case 0x2c:
                excluded = true;
                break;
            default:
                excluded = false;
                break;
            }
            if (!excluded)
                self->accesser->getStatusModule().changeStatusRequest(0x1f, self->accesser);
            fn_113_1B02C(self);
            break;
        }
        }
    }

    if (object->soGetKind() == 0 && value == 3) {
        switch (event->m_eventKind) {
        case 0x454:
            if (self->accesser->getStatusModule().getStatusKind() == 0x17 &&
                self->accesser->getLinkModule().isLink(3) == 1) {
                self->accesser->getStatusModule().changeStatusRequest(0x18, self->accesser);
            }
            break;
        }
    }

    fn_27_1DB0F0(self, event, accesser, object, value);
}
