#include <it/it_manager.h>
#include <it/item.h>
#include <so/so_module_accesser.h>
#include <so/area/so_area_module_impl.h>
#include <so/item/so_item_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" {
int fn_27_28DCF8(void* item);
BaseItem* fn_27_2A88C4(void* self, u32 id);
}

extern "C" int fn_96_15E44(void* process, soModuleAccesser* accesser) {
    soItemManageModule* itemManage = &accesser->getItemManageModule();
    soStatusModule* status = &accesser->getStatusModule();
    soAreaModule* area = &accesser->getAreaModule();
    int count = (int)area->getAreaContactCount(9);
    int n = 0;

    for (int i = 0; i < count && n < 4; i++) {
        u8* log = (u8*)area->getAreaContactLog(9, i);
        if (log[0xc] == 3) {
            BaseItem* item = fn_27_2A88C4(itManager::getInstance(), *(u32*)(log + 4));
            if (item != NULL && fn_27_28DCF8(item) != 0) {
                u32 kind = (u32)item->soGetSubKind();
                switch (kind) {
                case 0:
                case 13:
                case 20:
                case 27:
                case 29:
                    itemManage->haveItem(0x199, item, n + 3, false, false);
                    break;
                default:
                    itemManage->haveItem(0x199, item, n + 3, false, true);
                    break;
                }
                n++;
                if (accesser->getStatusModule().getStatusKind() != 0x112) {
                    if (accesser->getStatusModule().getStatusKind() != 0x117) {
                        return 1;
                    }
                }
            }
        }
    }

    if (n > 0) {
        status->changeStatusRequest(0x126, accesser);
        return 1;
    }
    return 0;
}
