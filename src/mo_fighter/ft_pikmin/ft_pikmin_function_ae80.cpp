#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

struct PikminEvent { int kind; int unused; int node; };
struct PikminHandler {
    char pad[0x60];
    soModuleAccesser* accesser;
    char rest[0x1FD08 - 0x64];
    char manager[0x184];
    char other[1];
};
class PikminArticle {
public:
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual int taskId();
};
class PikminArticles {
public:
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void detach(int, bool);
    virtual void s4C();
    virtual unsigned int exists(int);
    virtual int count(int);
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual PikminArticle* get(int);
};
class PikminList {
public:
    virtual void s08(); virtual void s0C();
    virtual StageObject** get(int);
    virtual int size();
};
extern "C" {
int fn_113_243CC(void*);
StageObject* fn_113_244FC(void*);
PikminList* fn_113_24550(void*);
void fn_113_24558(void*, void*);
void fn_113_24D3C(void*, StageObject*, Vec2f*);
unsigned int fn_113_2512C(void*);
void fn_113_25330(void*, StageObject*);
void fn_113_25344(void*, unsigned int);
void fn_113_255CC(void*, bool, int, bool);
void fn_113_23FD8(void*, unsigned int);
void fn_113_25530(void*);
void fn_113_1094C(soModuleAccesser*);
void fn_27_15B2DC(void*);
void fn_27_1324D4(PikminHandler*, PikminEvent*, soModuleAccesser*, StageObject*, int);
void fn_113_B7F0(Vec2f*, const Vec3f*);
int* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
int getStatusKind__23soExternalValueAccesserFP11StageObject(StageObject*);
}
static inline PikminArticles* articles(soModuleAccesser* a) {
    return (PikminArticles*)a->m_enumerationStart->m_generateArticleManageModule;
}
struct PikminTargetBase { char pad[0x3c]; };
class PikminTarget : public PikminTargetBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void action(int);
};
static inline void action(StageObject* obj, int status) {
    ((PikminTarget*)obj)->action(status);
}
extern "C" void fn_113_AE80(PikminHandler* self, PikminEvent* event, soModuleAccesser* accesser, StageObject* object, int value) {
    int status = self->accesser->getStatusModule().getStatusKind();
    switch (event->kind) {
    case 0x455:
        if (self->accesser->getStatusModule().getStatusKind() == 0x34 ||
            self->accesser->getStatusModule().getStatusKind() == 0x36 ||
            self->accesser->getStatusModule().getStatusKind() == 0x38)
            self->accesser->getStatusModule().changeStatusRequest(0x39, self->accesser);
        break;
    case 0x456:
        if (status == 0x34 || status == 0x38 || status == 0x36) {
            accesser->getWorkManageModule().onFlag(0x22000010);
            accesser->getWorkManageModule().onFlag(0x22000011);
        } else if (status == 0x39) {
            if (self->accesser->getSituationModule().getKind() == 0)
                self->accesser->getStatusModule().changeStatusRequest(0, self->accesser);
            else
                self->accesser->getStatusModule().changeStatusRequest(0xe, self->accesser);
        }
        break;
    case 0x457:
        if ((self->accesser->getStatusModule().getStatusKind() == 0x34 ||
             self->accesser->getStatusModule().getStatusKind() == 0x36 ||
             self->accesser->getStatusModule().getStatusKind() == 0x38 ||
             self->accesser->getStatusModule().getStatusKind() == 0x39 ||
             self->accesser->getStatusModule().getStatusKind() == 0x3a) &&
            (fn_113_243CC(self->manager) <= 0 ||
             object->m_taskId == fn_113_244FC(self->manager)->m_taskId)) {
            accesser->getWorkManageModule().onFlag(0x22000011);
            self->accesser->getStatusModule().changeStatusRequest(0x3b, self->accesser);
        }
        break;
    case 0x458: self->accesser->getStatusModule().changeStatusRequest(0x118, self->accesser); break;
    case 0x459: self->accesser->getStatusModule().changeStatusRequest(0x119, self->accesser); break;
    case 0x45a: self->accesser->getStatusModule().changeStatusRequest(0x11a, self->accesser); break;
    case 0x45b:
        if (articles(self->accesser)->count(0) >= 6 && fn_113_2512C(self->manager) == 1)
            fn_27_15B2DC((char*)self + 0x13c);
        break;
    case 0x45c:
        if (object->soGetKind() == 2 && object->soGetSubKind() == 0x43)
            fn_113_25344(self->manager, object->m_taskId);
        break;
    }
    if (object->soGetKind() == 2 && object->soGetSubKind() == 0x90) {
        switch (event->kind) {
        case 0x83b:
            if (object->soGetKind() == 2 && object->soGetSubKind() == 0x90) {
                int* constant = getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xa80e, 0);
                accesser->getWorkManageModule().setInt(*constant, 0x20000001);
                accesser->getStatusModule().changeStatusRequest(0x81, accesser);
                if (articles(accesser)->exists(2) == 1) {
                    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
                    if ((unsigned int)link->link(3, articles(accesser)->get(2)->taskId()) == 1) {
                        const soModuleEnumeration* modules = accesser->m_enumerationStart;
                        link = modules->m_linkModule;
                        link->setModelConstraintPosOrt(3, modules->m_modelModule->getCorrectNodeId(0x12e), event->node, 5, false);
                    }
                }
            }
            break;
        case 0x83c:
            if (object->soGetKind() == 2 && object->soGetSubKind() == 0x90) {
                articles(accesser)->detach(2, false);
                if (accesser->getGroundModule().isStCliff(0)) {
                    accesser->getStatusModule().changeStatusRequest(0x75, accesser);
                    Vec3f pos = self->accesser->getPostureModule().getPos();
                    Vec2f pos2;
                    fn_113_B7F0(&pos2, &pos);
                    PikminList* list = fn_113_24550(self->manager);
                    for (int i = 0; i < list->size(); i++) {
                        StageObject* target = *list->get(i);
                        fn_113_24D3C(self->manager, target, &pos2);
                        fn_113_25330(self->manager, target);
                        action(target, 0x33);
                    }
                } else {
                    accesser->getStatusModule().changeStatusRequest(0x7b, accesser);
                    PikminList* list = fn_113_24550(self->manager);
                    for (int i = 0; i < list->size(); i++)
                        action(*list->get(i), 8);
                    fn_113_24558(self->manager, self->other);
                }
                fn_113_1094C(self->accesser);
            }
            break;
        case 0x83d: {
            PikminList* list = fn_113_24550(self->manager);
            for (int i = 0; i < list->size(); i++) {
                int s = getStatusKind__23soExternalValueAccesserFP11StageObject(*list->get(i));
                if ((unsigned int)(s - 0x2e) <= 1)
                    action(*list->get(i), 0x30);
            }
            break;
        }
        case 0x83e:
            accesser->getStatusModule().changeStatusRequest(0x83, accesser);
            return;
        case 0x83f:
            fn_113_255CC(self->manager, 1, event->node, 1);
            break;
        }
    } else if (object->soGetKind() == 2 && object->soGetSubKind() == 0x43) {
        switch (event->kind) {
        case 0x45b:
            if (articles(self->accesser)->count(0) >= 6 && fn_113_2512C(self->manager) == 1)
                fn_27_15B2DC((char*)self + 0x13c);
            break;
        case 2:
            fn_113_23FD8(self->manager, object->m_taskId);
            fn_113_25530(self->manager);
            break;
        }
    }
    fn_27_1324D4(self, event, accesser, object, value);
}