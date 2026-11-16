#include <it/item.h>
#include <so/event/so_event_system.h>
#include <so/item/so_item_manage_event_presenter.h>
#include <so/item/so_item_pick_transactor_impl.h>
#pragma force_active on

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
    virtual void slot8(BaseItem*, int, int);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
};
struct ItemFlags {
    unsigned char f7 : 1;
    unsigned char f6 : 1;
    unsigned char f0 : 6;
};
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
    virtual void fn_27_B8780(BaseItem*);
    char pad[0x2c];
    short a;
    short b;
    soInstanceManagerFullProperty<soItemManageEventObserver*>* cache;
    soArray<soItemInfo>* items;
};
}
extern "C" {
extern char lbl_27_bss_CC0[];
extern char lbl_27_data_175C8[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

typedef soInstanceManagerFullProperty<soItemManageEventObserver*> ObserverList;
inline short getManageId(const matching::soNullable* self) { return self->a; }
inline bool checkManageId(const matching::soNullable* self) {
    const int id = getManageId(self);
    return soEventSystem::getInstance()->getInstanceManager().isContain(id);
}
inline ObserverList* selectList(matching::soNullable* self) {
    short id1 = self->a;
    short id2;
    soEventManager* mgr;
    ObserverList* cur;
    soEventUnitWrapper<soItemManageEventObserver>* unit;
    int flag;
    if (id1 <= -1) return (ObserverList*)lbl_27_bss_CC0;
    if (self->cache != 0) goto C;
    if (id1 <= -1 || checkManageId(self) == 0) {
        flag = 0;
        goto CHECK;
    }
    if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }
    id2 = self->b;
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(id2) == 0) cur = 0;
    else {
        unit = (soEventUnitWrapper<soItemManageEventObserver>*)__dynamic_cast(mgr->getEventUnit(id2), 0, lbl_27_data_175C8, __RTTI__11soEventUnit, 0);
        if (unit == 0) cur = 0;
        else cur = unit->getObserverListSub();
    }
    self->cache = cur;
    flag = (cur != 0);
CHECK:
    if (flag == 0) return (ObserverList*)lbl_27_bss_CC0;
C:
    mgr = soEventSystem::getInstance()->getManager(self->a);
    if (mgr->getObserverCapacity(self->b) == 0) {
        self->cache = 0;
        return (ObserverList*)lbl_27_bss_CC0;
    }
    return self->cache;
}

extern "C" void fn_27_BB398(matching::soNullable* self, int a, unsigned int b, int c) {
    if (self->fn_27_B83F4(a) == 0) return;
    BaseItem* item = self->items->at(a).m_item;
    ObserverList* sel = selectList(self);
    int n = sel->size();
    for (int i = 0; i < n; i++) {
        ((Object_vptr_0*)sel->atIndex(i))->slot8(item, a, c);
    }
    soItemInfo* ent = &self->items->at(a);
    ent->m_item = 0;
    ent->m_kind = (itKind)-1;
    ent->m_trait = (itParam::TraitFlag)0;
    ent->m_size = (itParam::SizeKind)2;
    ItemFlags* flags = (ItemFlags*)((char*)ent + 0x10);
    flags->f7 = 1;
    flags->f6 = 0;
    flags->f0 = 0xFE;
    if (b == 1U) self->fn_27_B8780(item);
}
