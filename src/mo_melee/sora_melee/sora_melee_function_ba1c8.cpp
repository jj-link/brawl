#include <it/item.h>
#include <so/event/so_event_system.h>
#include <mt/mt_vector.h>
#pragma force_active on

namespace matching {
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_B81C4();
    virtual void fn_27_B8360();
    virtual void fn_27_B83E4();
    virtual void fn_27_B8674();
    virtual void fn_27_B86B0();
    virtual void fn_27_B87B8();
    virtual void fn_27_B88AC();
    virtual void fn_27_B8A98();
    virtual void fn_27_B8B44();
    virtual void fn_27_BC19C();
    virtual void fn_27_B91FC();
    virtual void fn_27_B86D4();
    virtual void fn_27_BE4F0();
    virtual int fn_27_B83F4(int);
    virtual void fn_27_B8434();
    virtual void fn_27_B8468();
    virtual void fn_27_B849C();
    virtual void fn_27_B84D0();
    virtual void fn_27_B8548();
    virtual void fn_27_B8594();
    virtual void fn_27_B85E0();
    virtual void fn_27_BE4E8();
    virtual void fn_27_BE4E0();
    virtual void fn_27_BE4D8();
    virtual void fn_27_B8648();
    virtual void fn_27_B8780();
    virtual void fn_27_BC0A4();
    virtual void fn_27_BC0BC();
    virtual void fn_27_B9918();
    virtual void fn_27_B9D20();
    virtual void fn_27_BA1C8(int, float, float);
    virtual void fn_27_BA600();
    virtual void fn_27_BA514();
    virtual void fn_27_BA594();
    virtual void fn_27_BA714();
    virtual void fn_27_BA9B8();
    virtual void fn_27_BAA38();
    virtual void fn_27_BAAAC();
    virtual void fn_27_BAB24();
    virtual void fn_27_BAC38();
    virtual void fn_27_BACD4();
    virtual void fn_27_BB040();
    virtual void fn_27_BB0C0();
    virtual void fn_27_BB14C();
    virtual void fn_27_B9108();
    virtual void fn_27_B9878();
    virtual void fn_27_B97FC();
    virtual void fn_27_B9810();
    virtual void fn_27_BB658();
    virtual void fn_27_BE4D0();
    virtual void fn_27_BB398(int, int, int);

    char pad[0x2c];
    short a;
    short b;
    soInstanceManagerFullProperty<soItemManageEventObserver*>* cache;
    soArray<soItemInfo>* items;
    soItemNodeData* nodes;
    char pad40[0x28];
    soModuleAccesser* access;
};
}

extern "C" {
extern char lbl_27_bss_CC0[];
extern char lbl_27_data_175C8[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_E60;
extern const float lbl_27_rodata_E64;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_8003DC64(Vec2f*, float, Vec2f*);
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}

typedef soInstanceManagerFullProperty<soItemManageEventObserver*> ObserverList;

inline short getManageId(const matching::soNullable* self) {
    return self->a;
}

inline bool checkManageId(const matching::soNullable* self) {
    const short id = getManageId(self);
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline short getUnitId(const matching::soNullable* self) {
    return self->b;
}

inline ObserverList* selectList(matching::soNullable* self) {
    short id1;
    short id2;
    soEventManager* mgr;
    ObserverList* cur;
    soEventUnitWrapper<soItemManageEventObserver>* unit;
    int flag;

    id1 = self->a;
    if (id1 <= -1)
        return (ObserverList*)lbl_27_bss_CC0;

    if (self->cache != 0)
        goto C;

    if (id1 <= -1 || checkManageId(self) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = getUnitId(self);
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(id2) == 0) {
        cur = 0;
    } else {
        unit = (soEventUnitWrapper<soItemManageEventObserver>*)__dynamic_cast(
            mgr->getEventUnit(id2), 0, lbl_27_data_175C8,
            __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = unit->getObserverListSub();
    }

    self->cache = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (ObserverList*)lbl_27_bss_CC0;

C:
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        return (ObserverList*)lbl_27_bss_CC0;
    }
    return self->cache;
}

inline BaseItem* getItem(matching::soNullable* self, int index) {
    return self->items->at(index).m_item;
}

extern "C" void fn_27_BA1C8(matching::soNullable* self, int index, float angle, float speed)
{
    if (self->fn_27_B83F4(index) == 0)
        return;

    ObserverList* list = selectList(self);
    int count = list->size();

    for (int i = 0; i < count; i++) {
        BaseItem* item = getItem(self, index);
        list->atIndex(i)->notifyDropItem(item);
    }

    BaseItem* item2 = getItem(self, index);
    self->fn_27_BB398(index, 0, 0);

    float lr = self->access->m_enumerationStart->m_postureModule->getLr();
    Vec2f v;
    v.m_x = speed;
    v.m_y = lbl_27_rodata_E60;
    fn_8003DC64(&v, lbl_27_rodata_E64 * angle, &v);
    v.m_x *= lr;

    item2->setVisibilityWhole(1);

    Vec3f velocity;
    velocity.m_x = v.m_x;
    velocity.m_y = v.m_y;
    velocity.m_z = lbl_27_rodata_E60;
    fn_27_28E48C(item2, &velocity, lr);
}
