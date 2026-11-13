#include <types.h>
#include <so/stageobject.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

struct Pair {
    float x;
    float y;
};

struct Event {
    int kind;
    u32 pad;
    union {
        float x;
        StageObject* obj;
    };
    float y;
};

struct Speed {
    u32 a;
    u32 b;
};

class KineticView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Speed getSumSpeed(short*);
};

class PostureView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setPosition(Vec3f*);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void updateRotation();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void update();
};

class StatusView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(int, soModuleAccesser*);
};

class SituationView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int situation();
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_110_B860(void*, const void*);
void fn_27_1DB0F0(void*, Event*, soModuleAccesser*, StageObject*, int);
void fn_27_89544(void*, int);

extern const unsigned char lbl_110_data_60DC[];
extern const unsigned char lbl_110_data_6EB0[];
extern const unsigned char lbl_110_data_168C[];
extern const float lbl_110_rodata_88;
}

extern "C" void fn_110_11FDC(
    void* self, Event* ev, soModuleAccesser* acc, StageObject* sender, int ctx)
{
    const soModuleEnumeration* mods = acc->m_enumerationStart;
    soWorkManageModule* work = mods->m_workManageModule;
    KineticView* kinetic = (KineticView*)mods->m_kineticModule;
    PostureView* posture = (PostureView*)mods->m_postureModule;
    StatusView* status = (StatusView*)mods->m_statusModule;
    soLinkModule* link = mods->m_linkModule;
    u32 id;
    u32 w = *(u32*)((char*)sender + 0x2c);

    if (((s32)((w << 17) & 0xff800000) >> 24) == 10 &&
        (sender->soGetSubKind() == 0x15 || sender->soGetSubKind() == 0x31) &&
        link->isLink(3)) {
        id = *(u32*)((char*)sender + 0x28);
        u32 parentId = (u32)link->getParentTaskId(3);
        if (parentId == id) {
            Pair scaledSpeed;
            switch (ev->kind) {
            case 0x455: {
                void* e0 = __dynamic_cast(
                    kinetic->getEnergy(0), 0, lbl_110_data_60DC,
                    lbl_110_data_168C, 1);
                void* e1 = __dynamic_cast(
                    kinetic->getEnergy(1), 0, lbl_110_data_6EB0,
                    lbl_110_data_168C, 1);

                Pair p;
                p.x = ev->x;
                p.y = lbl_110_rodata_88;
                fn_110_B860((char*)e0 + 8, &p);
                *(float*)((char*)e1 + 8) = ev->y;

                Vec3f v = link->getParentModelNodeGlobalPosition(3, (u32)0, false);
                posture->setPosition(&v);
                link->getParentLr(3);
                posture->updateRotation();
                posture->update();
                link->removeModelConstraint(true);
                link->setModelConstraintAttribute(3, true);
                link->setAttribute(3, (soLinkConnection::Attribute)3, false);

                gfTaskScheduler::getInstance()->changeTaskPriorityRequest(
                    *(u32*)((char*)self + 0x28), 5);
                acc->m_enumerationStart->m_workManageModule->onFlag(0x12000002);
                work->onFlag(0x22000000);
                status->change(2, acc);
                return;
            }

            case 0x456:
                status->change(9, acc);
                return;

            case 0x457: {
                short flag = 1;
                Speed s = kinetic->getSumSpeed(&flag);
                fn_110_B860((char*)ev + 8, &s);
                if (((SituationView*)acc->m_enumerationStart->m_situationModule)
                        ->situation() == 0)
                    status->change(10, acc);
                else
                    status->change(13, acc);
                return;
            }

            case 0x458: {
                short flag = 1;
                Speed s = kinetic->getSumSpeed(&flag);
                fn_110_B860((char*)ev + 8, &s);
                return;
            }

            case 0x45a: {
                if (link->isModelConstraint())
                    link->removeModelConstraint(true);

                void* e = __dynamic_cast(
                    ((KineticView*)acc->m_enumerationStart->m_kineticModule)
                        ->getEnergy(0),
                    0, lbl_110_data_60DC, lbl_110_data_168C, 1);
                float scale = *(float*)(*(char**)((char*)self + 0x2980) + 0x90);
                *(Speed*)&scaledSpeed =
                    (const Speed&)(const Vec2f&)(*(Vec2f*)((char*)ev + 8) * scale);
                fn_110_B860((char*)e + 8, &scaledSpeed);
                *((u8*)e + 5) |= 0x80;
                fn_27_89544(acc->m_enumerationStart->m_kineticModule, 1);
                status->change(13, acc);
                return;
            }

            case 0x459:
                status->change(11, acc);
                return;

            case 0x45b:
                status->change(14, acc);
                return;

            case 0x3c:
                link->setModelConstraintAttribute(3, false);
                if (link->isModelConstraint()) {
                    link->removeModelConstraint(true);
                    status->change(13, acc);
                }
                break;

            case 0:
                work->onFlag(0x2200000b);
                break;
            }
        } else {
            goto other;
        }
    } else {
    other:
        if (link->isLink(5)) {
            id = *(u32*)((char*)sender + 0x28);
            u32 parentId = (u32)link->getParentTaskId(5);
            if (parentId == id) {
                switch (ev->kind) {
                case 0:
                    work->onFlag(0x2200000b);
                    break;
                }
                goto finish;
            }
        }

        switch (ev->kind) {
        case 0x3e:
            if (link->isLinked(6)) {
                switch (ev->obj->soGetSubKind()) {
                case 5:
                case 15:
                    acc->m_enumerationStart->m_linkModule->sendEventParents(
                        3, *(soLinkEventArgs*)ev);
                    break;
                }
            }
            break;
        }
    }

finish:
    fn_27_1DB0F0(self, ev, acc, sender, ctx);
}
