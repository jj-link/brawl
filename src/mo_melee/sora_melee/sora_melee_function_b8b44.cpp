#include <it/item.h>
#include <so/event/so_event_system.h>

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
    virtual unsigned int fn_27_B83F4(int);

    char pad[0x2c];
    short a;
    short b;
    soInstanceManagerFullProperty<soItemManageEventObserver*>* cache;
    soArray<soItemInfo>* items;
    soItemNodeData* nodes;
    char pad40[0x21];
    bool flag;
    char pad62[6];
    soModuleAccesser* access;
};

struct ItemInfoLocal {
    itKind m_kind;
    BaseItem* m_item;
    itParam::TraitFlag m_trait;
    itParam::SizeKind m_size;
    bool m_isVisible : 1;
    bool m_isHoldAnim : 1;
    unsigned char m_attachGroup : 6;
    char _0x11[3];
};

}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
};

extern "C" {
extern char lbl_27_bss_CC0[];
extern char lbl_27_data_175C8[];
extern char __RTTI__11soEventUnit[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_28DC0C(BaseItem*);
}

typedef soInstanceManagerFullProperty<soItemManageEventObserver*> ObserverList;

inline bool checkManageId(const matching::soNullable* self) {
    short id = self->a;
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}

inline ObserverList* selectList(matching::soNullable* self) {
    short id1 = self->a;
    short id2;
    soEventManager* mgr;
    ObserverList* cur;
    soEventUnitWrapper<soItemManageEventObserver>* unit;
    int flag;

    if (id1 <= -1)
        return (ObserverList*)lbl_27_bss_CC0;

    if (self->cache != 0)
        goto CHECK_CACHE;

    if (id1 <= -1 || !checkManageId(self)) {
        flag = 0;
        goto CHECK;
    }

    if (soEventSystem::getInstance()
            ->getManager(self->a)
            ->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->b;
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

CHECK_CACHE:
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        return (ObserverList*)lbl_27_bss_CC0;
    }
    return self->cache;
}

inline void setInfo(
    matching::soNullable* self, int slot, BaseItem* item, int kind,
    int param, itParam::SizeKind size, int val)
{
    bool f = self->flag;
    matching::ItemInfoLocal& info = (matching::ItemInfoLocal&)self->items->at(slot);
    info.m_item = item;
    info.m_kind = (itKind)kind;
    info.m_trait.m_mask = param;
    info.m_size = size;
    info.m_isVisible = f;
    info.m_isHoldAnim = 0;
    info.m_attachGroup = val;
}

extern "C" int fn_27_B8B44(
    matching::soNullable* self, int node, BaseItem* item,
    int index, bool arg4, unsigned int notify)
{
    int param = item->getParam((itValueAccesser::ParamInt)0x5bce);
    int kind = item->soGetSubKind();
    int slot = index;
    int n;

    if (item->isHaved() == 1 && !fn_27_28DC0C(item))
        return 0;

    if (notify == 1) {
        ObserverList* list = selectList(self);
        n = list->size();
        for (int i = 0; i < n; i++) {
            if (!list->atIndex(i)->notifyHaveItemPreCheck(item, (bool*)&slot))
                return 0;
        }
    }

    if (self->fn_27_B83F4(slot) == 1)
        return 0;

    itParam::SizeKind size;
    switch (item->getParam((itValueAccesser::ParamInt)0x5b69)) {
    case 0:
        n = 0;
        break;
    case 1:
        n = 1;
        break;
    default:
        return 0;
    }

    item->have(
        *(int*)((char*)*(void**)((char*)self->access + 8) + 0x28),
        node, -1);

    if (!item->isHaved())
        return 0;

    item->setVisibilityWhole(self->flag);

    int val = 0xfe;
    if (kind == 0xc || kind == 0x38)
        val = 2;

    setInfo(self, slot, item, kind, param, (itParam::SizeKind)n, val);

    if (notify == 1) {
        ObserverList* list = selectList(self);
        int count = list->size();
        for (int i = 0; i < count; i++) {
            itParam::SizeKind sz = self->items->at(index).m_size;
            list->atIndex(i)->notifyHaveItem(
                sz, item, node, slot, arg4);
        }
    }

    return 1;
}
