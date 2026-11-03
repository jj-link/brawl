#include <so/so_module_accesser.h>
#include <so/item/so_item_pick_transactor_impl.h>
#pragma force_active on

extern "C" void fn_96_16160(void* process, soModuleAccesser* accesser) {
    int var_r30 = 0;
    int var_r29 = 0;
    int var_r28 = 0;

    if (accesser->getWorkManageModule().isFlag(0x2200001C)) {
        switch (accesser->getWorkManageModule().getInt(0x20000005)) {
        case 1:
            var_r30 = 1;
            break;
        case 2:
            var_r28 = 1;
            break;
        }
    } else {
        soItemManageModule& item = accesser->getItemManageModule();
        for (int i = 3; i < 7; i++) {
            if (item.isHaveItem(i)) {
                soItemInfo info;
                item.getHaveItemInfo(&info, i);
                if (item.getHaveItemSize(i) == 1) {
                    var_r30 = 1;
                }
                if (info.m_trait.m_mask & 0x8000) {
                    var_r28 = 1;
                }
                if (info.m_trait.m_mask & 0x2000) {
                    var_r29 = 1;
                }
            }
        }
    }

    if (var_r28 != 0) {
        accesser->getWorkManageModule().setInt(0x1D4, 0x20000000);
        accesser->getWorkManageModule().setInt(0x1DE, 0x20000001);
        return;
    }
    if (var_r30 != 0) {
        accesser->getWorkManageModule().setInt(0x1D5, 0x20000000);
        accesser->getWorkManageModule().setInt(0x1DF, 0x20000001);
        return;
    }
    if (var_r29 != 0) {
        accesser->getWorkManageModule().setInt(0x1D3, 0x20000000);
        accesser->getWorkManageModule().setInt(0x1DD, 0x20000001);
        return;
    }
    accesser->getWorkManageModule().setInt(0x1D6, 0x20000000);
    accesser->getWorkManageModule().setInt(0x1E0, 0x20000001);
}
