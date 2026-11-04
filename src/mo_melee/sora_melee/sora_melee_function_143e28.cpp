#include <ft/ft_common_data_accesser.h>
#include <it/it_manager.h>
#include <types.h>
#pragma force_active on

struct ItKindTable {
    itKind* kinds;
    s32 count;
};

struct FtDataWithTable {
    u8 pad[0x60];
    ItKindTable* table;
};

extern "C" bool fn_27_145694(int);
extern "C" itManager* lbl_27_bss_6A34;

extern "C" void fn_27_143E28(int, ftKind kind) {
    if (fn_27_145694(kind) == 1) {
        FtDataWithTable* data = reinterpret_cast<FtDataWithTable*>(g_ftCommonDataAccesser.getData(kind));
        if (data->table != NULL) {
            for (s32 i = 0; i < data->table->count; i++) {
                if (lbl_27_bss_6A34 != NULL) {
                    if (!itManager::getInstance()->isCompItemKindArchive(data->table->kinds[i], 0, true)) {
                        itManager::getInstance()->preloadItemKindArchive(data->table->kinds[i], 0, (itArchive::Type)0, true);
                    }
                }
            }
        }
    }
}
