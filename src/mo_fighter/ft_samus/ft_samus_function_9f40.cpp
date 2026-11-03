#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <so/so_external_value_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct SamusEvent {
    int kind;
    bool handled;
    char pad[3];
    union { int node; float x; };
    float y, z;
};
struct SamusHandler {
    char pad[0x60];
    soModuleAccesser* accesser;
};
struct SamusParams {
    char pad[0x34];
    float angle;
    char pad2[0x10];
    float distance;
};
class SamusArticles {
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
    virtual unsigned int exists(int);
};
extern "C" {
void fn_27_1324D4(SamusHandler*, SamusEvent*, soModuleAccesser*, StageObject*, int);
extern const float lbl_94_rodata_0[];
}
extern "C" void fn_94_9F40(SamusHandler* self, SamusEvent* event, soModuleAccesser* accesser, StageObject* object, int value) {
    const float* constants = lbl_94_rodata_0;
    switch (object->soGetSubKind()) {
    case 0x54:
        switch (event->kind) {
        case 0x838:
            switch (self->accesser->m_enumerationStart->m_statusModule->getStatusKind()) {
            case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8:
            case 10: case 11: case 12: case 13: case 14: case 15:
            case 17: case 18: case 21: case 22: case 23: case 24:
            case 0x115: case 0x11d: case 0x11e: {
                SamusParams* p = *(SamusParams**)((char*)g_ftCommonDataAccesser.getData((ftKind)3) + 0x84);
                Vec3f pos = accesser->m_enumerationStart->m_postureModule->getPos();
                Vec3f target = soExternalValueAccesser::getPos(object);
                float ratio = (pos.m_x - target.m_x) / p->distance;
                if (ratio >= constants[1]) ratio = constants[1];
                if (ratio <= constants[8]) ratio = constants[8];
                float result = constants[9] + -p->angle * ratio;
                accesser->m_enumerationStart->m_workManageModule->setFloat(result, 0x11000013);
                self->accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x11f, self->accesser);
                self->accesser->m_enumerationStart->m_controllerModule->setRumble(0, 10, false, -1);
                event->handled = true;
                break;
            }
            default:
                break;
            }
            return;
        }
    case 0x84:
        switch (event->kind) {
        case 0x838:
            if (self->accesser->m_enumerationStart->m_linkModule->isLinked(0) == 1) {
                StageObject* target = self->accesser->m_enumerationStart->m_linkModule->getNode(0);
                if (target) {
                    Vec3f pos = soExternalValueAccesser::getPos(target);
                    event->x = pos.m_x;
                    event->y = pos.m_y;
                    event->z = pos.m_z;
                    event->handled = true;
                }
            }
            break;
        case 0x839:
            self->accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x39, self->accesser);
            return;
        case 0x83a:
            event->node = accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x12e);
            event->handled = true;
            return;
        case 0x83b:
            accesser->m_enumerationStart->m_workManageModule->setInt(*(int*)soValueAccesser::getConstantIndefinite(accesser, 0xa80e, 0), 0x20000001);
            self->accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x81, self->accesser);
            if (static_cast<SamusArticles*>(accesser->m_enumerationStart->m_generateArticleManageModule)->exists(7) == 1) {
                accesser->m_enumerationStart->m_linkModule->removeModelConstraint(false);
                constants = reinterpret_cast<const float*>(accesser->m_enumerationStart->m_linkModule);
                reinterpret_cast<soLinkModule*>(const_cast<float*>(constants))->setModelConstraintPosOrt(3, accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x12e), event->node, 5, false);
            }
            return;
        case 0x83c:
            if (accesser->m_enumerationStart->m_groundModule->isStCliff(0))
                accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x75, accesser);
            else
                accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x7b, accesser);
            return;
        case 0x83e:
            accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x83, accesser);
            return;
        }
    }
    fn_27_1324D4(self, event, accesser, object, value);
}