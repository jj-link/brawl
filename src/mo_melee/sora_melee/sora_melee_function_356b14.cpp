#include <it/it_manager.h>
#include <it/item.h>
#include <gf/gf_task.h>
#include <so/area/so_area_module_impl.h>
#include <so/item/so_item_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <types.h>

#pragma force_active on

extern "C" {
int fn_27_28DCF8(void*);
BaseItem* fn_27_2A88C4(void*, u32);
int getParam__8BaseItemFQ215itValueAccesser8ParamInt(BaseItem*, int);
void* fn_27_30FA2C(void*, int, int, void*, int);
extern int lbl_27_bss_7B0C;
}

struct Prefix8 {
    char pad[8];
};

class Obj12 : public Prefix8 {
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
    virtual int method12c(int);
};

struct ModBlock {
    char pad0[4];
    Obj12* obj;
    char pad1[0x54 - 8];
    soLinkModule* link;
    char pad2[0x64 - 0x58];
    soWorkManageModule* work;
    char pad3[0x70 - 0x68];
    soStatusModule* status;
    char pad4[0x90 - 0x74];
    soAreaModule* area;
    char pad5[0xA8 - 0x94];
    soItemManageModule* items;
};

struct Ctx {
    char pad0[8];
    StageObject* stageObject;
    char pad1[0xD8 - 0x0C];
    ModBlock* modules;
};

struct LocalEvent {
    int type;
    unsigned char zero;
};

extern "C" void fn_27_356B14(void*, Ctx* self) {
    ModBlock* modules = self->modules;
    soWorkManageModule* work = modules->work;
    soItemManageModule* items = modules->items;
    soStatusModule* status = modules->status;
    soAreaModule* area = modules->area;
    int hasParam = 0;
    int hasBit13 = 0;
    int hasBit15 = 0;
    int interrupted = 0;

    int areaID = work->getInt(0x20000006);
    int count = area->getAreaContactCount(areaID);
    int n = 0;
    int i = 0;

    while (i < count && n < 4) {
        soAreaContactLog* log = area->getAreaContactLog(areaID, i);
        if (((u8*)log)[0xC] == 3) {
            BaseItem* item = fn_27_2A88C4(
                itManager::getInstance(), *(u32*)((char*)log + 4));
            if (item != 0) {
                int param = getParam__8BaseItemFQ215itValueAccesser8ParamInt(
                    item, 0x5BCE);
                if (fn_27_28DCF8(item) != 0) {
                    int value = self->modules->obj->method12c(0x12C);
                    switch ((u32)item->soGetSubKind()) {
                    case 0:
                    case 13:
                    case 20:
                    case 27:
                    case 29:
                        items->haveItem(value, item, n + 3, false, false);
                        break;
                    default:
                        items->haveItem(value, item, n + 3, false, true);
                        break;
                    }
                    ++n;
                    if (getParam__8BaseItemFQ215itValueAccesser8ParamInt(
                            item, 0x5B69) == 1) {
                        hasParam = 1;
                    }
                    if (param & 0x8000) {
                        hasBit15 = 1;
                    }
                    if (param & 0x2000) {
                        hasBit13 = 1;
                    }
                    if (self->modules->status->getStatusKind() != 0x112 &&
                        self->modules->status->getStatusKind() != 0x117 &&
                        self->modules->status->getStatusKind() != 0x14B &&
                        self->modules->status->getStatusKind() != 0x14C) {
                        interrupted = 1;
                        break;
                    }
                }
            }
        }
        ++i;
    }

    int id = work->getInt(0x20000007);
    if ((u32)id != 0xFFFFFFFFU && gfTask::getTask(id)) {
        if (work->getInt(0x20000008) == 1) {
            hasBit15 = 1;
        }

        int kind = self->stageObject->soGetSubKind();
        int index = ((~((kind - 5) | (5 - kind))) >> 31) + 8;
        self->modules->link->link(index, id);

        LocalEvent event;
        event.type = 0x835;
        event.zero = 0;
        self->modules->link->sendEventParents(
            index, *(soLinkEventArgs*)&event);
        ++n;
    }

    if (!interrupted && n > 0) {
        int statusKind;
        if (hasBit15) {
            statusKind = 0x11E;
        } else if (hasParam) {
            statusKind = 0x11F;
        } else {
            statusKind = 0x120;
            if (hasBit13) {
                statusKind = 0x11D;
            }
        }

        void* accesser = fn_27_30FA2C(
            &lbl_27_bss_7B0C, 0, statusKind, self, 1);
        status->changeStatusRequest((int)accesser, (soModuleAccesser*)self);
    }
}
