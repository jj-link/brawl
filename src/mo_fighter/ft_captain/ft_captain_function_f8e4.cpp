#include <ft/ft_manager.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

struct CaptainHit {
    unsigned char reserved[0x28];
};

struct CaptainOwner {
    unsigned char reserved[0xd8];
    soModuleEnumeration* modules;
};

extern "C" {
extern CaptainHit* lbl_100_bss_268;
int fn_27_10B21C(ftManager* manager, int* entries);
int fn_100_F9FC(CaptainOwner* self, CaptainHit* hit, Fighter* fighter);
}

extern "C" void fn_100_F8E4(CaptainOwner* self) {
    soModuleEnumeration* modules = self->modules;
    soWorkManageModule* work = modules->m_workManageModule;
    int i;
    int entry;
    int count = work->getInt(0x20000000);
    CaptainHit* hit = lbl_100_bss_268 + count;
    int entries[8];
    int n = fn_27_10B21C(g_ftManager, entries);
    for (i = 0; i < n; ++i) {
        entry = entries[i];
        if (fn_100_F9FC(self, hit, g_ftManager->getFighter(entry, -1))) {
            hit++;
            count++;
        }
        if (fn_100_F9FC(self, hit, g_ftManager->getSubFighter(entry))) {
            hit++;
            count++;
        }
    }
    work->setInt(count, 0x20000000);
}
