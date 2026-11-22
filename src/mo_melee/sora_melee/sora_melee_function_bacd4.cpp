#include <types.h>
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
    virtual unsigned fn_27_B83F4(int);
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
    virtual void fn_27_BA1C8();
    virtual void fn_27_BA600();
    virtual void fn_27_BA514();
    virtual void fn_27_BA594();
    virtual void fn_27_BA714();
    virtual void fn_27_BA9B8();
    virtual void fn_27_BAA38();
    virtual void fn_27_BAAAC();
    virtual void fn_27_BAB24();
    virtual void fn_27_BAC38();
    virtual void fn_27_BACD4(u8, int);

    char pad[0x2c];
    short a;
    short b;
    soInstanceManagerFullProperty<soItemManageEventObserver*>* cache;
    soArray<soItemInfo>* items;
    char pad3c[0x25];
    u8 visible;
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
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
};

extern "C" {
extern char lbl_27_bss_CC0[];
extern char lbl_27_data_175C8[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

typedef soInstanceManagerFullProperty<soItemManageEventObserver*> ObserverList;

inline bool checkManageId(const matching::soNullable* self, ObserverList*& list) {
    list = (ObserverList*)self->a;
    return soEventSystem::getInstance()->getInstanceManager().isContain((int)list);
}

struct ItemBits {
    char pad[16];
    unsigned char visible : 1;
    unsigned char hold : 1;
    unsigned char rest : 6;
};

extern "C" void fn_27_BACD4(matching::soNullable* self, u8 visible, int index) {
    int count;
    ObserverList* list;
    bool hold;
    BaseItem* item;
    int i;
    int flag;

    if (index == -1) {
        count = self->items->size();
        for (i = 0; i < count; i++) {
            self->fn_27_BACD4(visible, i);
        }
        goto END;
    }

    if (self->fn_27_B83F4(index) == 1) {
        if (visible != (((ItemBits*)&self->items->at(index))->visible != 0)) {
            ((ItemBits*)&self->items->at(index))->visible = visible;
            self->items->at(index).m_item->setVisibilityWhole(visible);

            short id1;
            ObserverList* cur;
            soEventUnitWrapper<soItemManageEventObserver>* unit;

            id1 = self->a;
            if (id1 <= -1) {
                list = (ObserverList*)lbl_27_bss_CC0;
                goto LOOP;
            }
            if (self->cache != 0) {
                goto C;
            }
            if (id1 <= -1 || checkManageId(self, list) == 0) {
                flag = 0;
                goto CHECK;
            }
            if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
                self->cache = 0;
                flag = 0;
                goto CHECK;
            }
            count = self->b;
            list = (ObserverList*)soEventSystem::getInstance()->getManager(self->a);
            if (((soEventManager*)list)->getObserverCapacity(count) == 0) {
                cur = 0;
            } else {
                unit = (soEventUnitWrapper<soItemManageEventObserver>*)__dynamic_cast(
                    ((soEventManager*)list)->getEventUnit(count), 0, lbl_27_data_175C8,
                    __RTTI__11soEventUnit, 0);
                if (unit == 0) {
                    cur = 0;
                } else {
                    cur = unit->getObserverListSub();
                }
            }
            self->cache = cur;
            flag = (cur != 0);

        CHECK:
            if (flag == 0) {
                list = (ObserverList*)lbl_27_bss_CC0;
                goto LOOP;
            }

        C:
            if (soEventSystem::getInstance()->getManager(self->a)->getObserverCapacity(self->b) == 0) {
                self->cache = 0;
                list = (ObserverList*)lbl_27_bss_CC0;
                goto LOOP;
            }
            list = self->cache;

        LOOP:
            {
                int j;
                count = list->size();
                for (j = 0; j < count; j++) {
                    hold = (((ItemBits*)&self->items->at(index))->hold != 0);
                    item = self->items->at(index).m_item;
                    list->atIndex(j)->notifyVisibilityItem(item, index, hold, visible);
                }
            }
        }
    }

    if (index == 0) {
        self->visible = visible;
    }

END:
    return;
}
