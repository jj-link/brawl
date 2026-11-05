#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct PokeEvent {
    int kind;
    int pad;
    int node;
};

class PokeArticle {
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

class PokeArticles {
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
    virtual PokeArticle* get(int);
};

extern "C" {
void fn_27_377B30(soModuleAccesser*, void*);
void fn_27_12D904(void*, bool, bool, int);
int* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
void fn_27_1324D4(void*, PokeEvent*, soModuleAccesser*, StageObject*, int);
}

static inline PokeArticles* articles(soModuleAccesser* accesser) {
    return static_cast<PokeArticles*>(accesser->m_enumerationStart->m_generateArticleManageModule);
}

extern "C" void fn_116_1FAC4(void* self, PokeEvent* event, soModuleAccesser* accesser, StageObject* object, int eventType) {
    switch (event->kind) {
    case 0x455:
        fn_27_377B30(accesser, &event->node);
        fn_27_12D904(self, true, true, 0);
        break;
    case 0x83B:
        accesser->m_enumerationStart->m_workManageModule->setInt(
            *getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xA80E, 0),
            0x20000001);
        accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x81, accesser);
        if (articles(accesser)->exists(2) == 1) {
            soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
            if ((unsigned int)link->link(3, articles(accesser)->get(2)->taskId()) == 1) {
                link = accesser->m_enumerationStart->m_linkModule;
                link->setModelConstraintPosOrt(3, accesser->m_enumerationStart->m_modelModule->getCorrectNodeId(0x12E), event->node, 5, false);
            }
        }
        break;
    case 0x83C:
        if (accesser->m_enumerationStart->m_groundModule->isStCliff(0)) {
            accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x75, accesser);
        } else {
            accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x7B, accesser);
        }
        break;
    case 0x83E:
        accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x83, accesser);
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}