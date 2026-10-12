#include <so/stageobject.h>

struct NessLinkEnergyEvent {
    int kind;
    unsigned int dispatcher;
    union { int objectId; float value; };
    union { int linkValue; float speed[2]; };
    float acceleration[2];
    float limit[2];
};

struct NessEnergySpeed { float x; float y; };
// This energy returns its two speed words in r3/r4, unlike Vec2f's hidden result.
class NessLinkEnergyView : public soNullable {
public:
    virtual void updateEnergy(soModuleAccesser*);
    virtual NessEnergySpeed getSpeed();
};

extern "C" {
extern const char lbl_101_data_9840[], lbl_101_data_3890[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_101_FE5C(void*, const void*);
void fn_27_1DB0F0(void*, NessLinkEnergyEvent*, soModuleAccesser*, StageObject*, int);
}

extern "C" void fn_101_237F8(void* observer, NessLinkEnergyEvent* event,
                             soModuleAccesser* accesser, StageObject* sender, int context) {
    if (sender->soGetKind() == 0 && sender->soGetSubKind() == 10) {
        switch (event->kind) {
        case 0x455: {
            soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
            soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
            if (!link->isLink(5)) {
                link->link(5, event->objectId);
                work->setInt(event->objectId, 0x20000000);
                work->setInt(event->linkValue, 0x20000001);
            }
            return;
        }
        case 0x456: {
            accesser->m_enumerationStart->m_collisionAttackModule->setPowerMul(event->value);
            return;
        }
        }
    } else if (sender->soGetKind() == 2 && sender->soGetSubKind() == 0x6b) {
        switch (event->kind) {
        case 0x838: {
            soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
            work->onFlag(0x22000004);
            NessLinkEnergyView* energy = static_cast<NessLinkEnergyView*>(__dynamic_cast(
                accesser->getKineticModule().getEnergy(0), 0,
                lbl_101_data_9840, lbl_101_data_3890, 1));
            work->setFloat(event->value, 0x21000000);
            NessEnergySpeed speed = energy->getSpeed();
            fn_101_FE5C(event->speed, &speed);
            fn_101_FE5C(event->acceleration,
                reinterpret_cast<const char*>(energy) + 0x10);
            fn_101_FE5C(event->limit,
                reinterpret_cast<const char*>(energy) + 0x28);
            accesser->getKineticModule().changeKinetic(2, accesser);
            return;
        }
        }
    }
    fn_27_1DB0F0(observer, event, accesser, sender, context);
}
