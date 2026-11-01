#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <so/link/so_link_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#pragma force_active on

class DiddyCatchModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void setTarget(unsigned int);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void clearCatch(int);
    virtual void slot3C();
    virtual void releaseCatch(int);
};

struct DiddyEvent {
    int kind;
    bool handled;
    unsigned char padding05[7];
    int status;
    unsigned char padding10[12];
    bool flag;
};

struct DiddyHandler {
    unsigned char padding00[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
extern const float lbl_115_rodata_C;
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_27_1324D4(DiddyHandler*, DiddyEvent*, soModuleAccesser*, StageObject*, int);
}

static inline DiddyCatchModule* catchModule(soModuleAccesser* accesser) {
    return static_cast<DiddyCatchModule*>(
        accesser->m_enumerationStart->m_catchModule);
}

extern "C" void fn_115_950C(DiddyHandler* self, DiddyEvent* event,
                            soModuleAccesser* accesser, StageObject* object,
                            int value) {
    switch (event->kind) {
    case 8:
        if (event->status == 0xD6) {
            if (self->accesser->getStatusModule().getStatusKind() == 0x11B ||
                self->accesser->getStatusModule().getStatusKind() == 0x124) {
                self->accesser->getStatusModule().changeStatusRequest(
                    0x11E, self->accesser);
                event->handled = true;
                event->flag = false;
                catchModule(self->accesser)->setTarget(object->m_taskId);
                return;
            }
        }
        break;

    case 36:
        if (self->accesser->getStatusModule().getStatusKind() == 0x11F ||
            self->accesser->getStatusModule().getStatusKind() == 0x121) {
            Vec3f rotation = self->accesser->getPostureModule().getRot(0);
            self->accesser->getLinkModule().adjustModelConstraintPosture(
                reinterpret_cast<Matrix*>(fn_115_8EF8(
                    &const_cast<Vec3f&>(static_cast<const Vec3f&>(Vec3f())),
                    lbl_115_rodata_C, lbl_115_rodata_C, lbl_115_rodata_C)),
                fn_115_8EF8(
                    &const_cast<Vec3f&>(static_cast<const Vec3f&>(Vec3f())),
                    lbl_115_rodata_C, lbl_115_rodata_C, lbl_115_rodata_C));
            self->accesser->getPostureModule().setRot(&rotation, 0);
            self->accesser->getPostureModule().initRotYLr();
            self->accesser->getStageObject().updateNodeSRT();
            catchModule(self->accesser)->releaseCatch(0);
            catchModule(self->accesser)->clearCatch(0);
            return;
        }
        break;

    case 14:
        if (self->accesser->getStatusModule().getStatusKind() == 0x11F ||
            self->accesser->getStatusModule().getStatusKind() == 0x121) {
            const Vec3f& rotation = self->accesser->getPostureModule().getRot(0);
            self->accesser->getLinkModule().adjustModelConstraintPosture(
                reinterpret_cast<Matrix*>(fn_115_8EF8(
                    &const_cast<Vec3f&>(static_cast<const Vec3f&>(Vec3f())),
                    lbl_115_rodata_C, lbl_115_rodata_C, lbl_115_rodata_C)),
                fn_115_8EF8(
                    &const_cast<Vec3f&>(static_cast<const Vec3f&>(Vec3f())),
                    lbl_115_rodata_C, lbl_115_rodata_C, lbl_115_rodata_C));
            self->accesser->getPostureModule().setRot(
                const_cast<Vec3f*>(&rotation), 0);
            self->accesser->getPostureModule().initRotYLr();
            self->accesser->getStageObject().updateNodeSRT();
            catchModule(self->accesser)->releaseCatch(0);
            catchModule(self->accesser)->clearCatch(0);
            self->accesser->getStatusModule().changeStatusRequest(
                14, self->accesser);
        }
        break;
    }

    fn_27_1324D4(self, event, accesser, object, value);
}
