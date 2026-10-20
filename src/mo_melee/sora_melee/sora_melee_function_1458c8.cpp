#include <types.h>
#pragma force_active on

class utArchiveManager {
public:
    void* getPublicAddress(u32, const char*, u16, u32, u32);
};

class soArchiveDb {
public:
    static utArchiveManager* getManager(u32);
};

extern "C" {
extern void* g_ftSlotManager;
extern char lbl_27_data_2BBD8[];
extern void* fn_27_1222C8(void*);

void* fn_27_1458C8() {
    void* p = fn_27_1222C8(g_ftSlotManager);
    utArchiveManager* mgr = soArchiveDb::getManager(0);
    return mgr->getPublicAddress((u32)p, lbl_27_data_2BBD8, 0, 0, -1);
}
}
