#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct LucasEvent {
    int kind;
    bool handled;
    char padding[3];
    union {
        int node;
        float x;
    };
    float y;
    float z;
};

struct LucasHandler {
    char padding[0x60];
    soModuleAccesser* accesser;
};

class LucasArticle {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual int taskId();
};

class LucasArticles {
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
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual LucasArticle* get(int);
};

extern "C" {
Vec3f getPos__23soExternalValueAccesserFP11StageObject(StageObject*);
int* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_27_1324D4(
    LucasHandler*, LucasEvent*, soModuleAccesser*, StageObject*, int);
}

static inline LucasArticles* articles(soModuleAccesser* accesser) {
    return static_cast<LucasArticles*>(
        accesser->m_enumerationStart->m_generateArticleManageModule);
}

extern "C" void fn_114_BA10(
    LucasHandler* self,
    LucasEvent* event,
    soModuleAccesser* accesser,
    StageObject* object,
    int eventType)
{
    if (object->soGetKind() == 2) {
        switch (object->soGetSubKind()) {
        case 0x52:
            switch (event->kind) {
            case 0x838:
                if (self->accesser->m_enumerationStart->m_linkModule->isLinked(0)) {
                    StageObject* target =
                        self->accesser->m_enumerationStart->m_linkModule->getNode(0);
                    if (target) {
                        Vec3f position =
                            getPos__23soExternalValueAccesserFP11StageObject(target);
                        event->x = position.m_x;
                        event->y = position.m_y;
                        event->z = position.m_z;
                        event->handled = true;
                    }
                }
                break;
            case 0x839:
                accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                    0x39, accesser);
                break;
            case 0x83B:
                accesser->m_enumerationStart->m_workManageModule->setInt(
                    *getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(
                        accesser, 0xA80E, 0),
                    0x20000001);
                accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                    0x81, accesser);
                if (articles(accesser)->exists(4) == 1) {
                    soLinkModule* link =
                        accesser->m_enumerationStart->m_linkModule;
                    if ((unsigned int)link->link(
                            3, articles(accesser)->get(4)->taskId()) == 1) {
                        link = accesser->m_enumerationStart->m_linkModule;
                        link->setModelConstraintPosOrt(
                            3,
                            accesser->m_enumerationStart->m_modelModule
                                ->getCorrectNodeId(0x12E),
                            event->node,
                            5,
                            false);
                    }
                }
                break;
            case 0x83C:
                if (accesser->m_enumerationStart->m_groundModule->isStCliff(0)) {
                    accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                        0x75, accesser);
                } else {
                    accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                        0x7B, accesser);
                }
                break;
            case 0x83E:
                accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                    0x83, accesser);
                break;
            case 0x83A:
                event->node =
                    accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(
                        0x12E);
                event->handled = true;
                break;
            }
            break;

        case 0x4D:
            switch (event->kind) {
            case 0x838:
                if (accesser->m_enumerationStart->m_statusModule->getStatusKind()
                    == 0x117) {
                    accesser->m_enumerationStart->m_statusModule->changeStatusRequest(
                        0x119, accesser);
                }
                break;
            }
            return;

        case 0x4F:
            switch (event->kind) {
            case 0x838:
                if (accesser->m_enumerationStart->m_linkModule->isLink(6)) {
                    accesser->m_enumerationStart->m_linkModule->unlink(6);
                }
                break;
            }
            return;
        }
    }

    fn_27_1324D4(self, event, accesser, object, eventType);
}
