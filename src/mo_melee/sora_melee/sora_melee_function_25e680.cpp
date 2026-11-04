#include <ft/ft_manager.h>
#include <ft/ft_owner.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

extern char lbl_27_data_54630[];
extern char lbl_27_data_54660[];

extern "C" void fn_27_25E680() {
    OSReport(lbl_27_data_54630);
    int entryId = g_ftManager->getEntryId(0);
    if (g_ftManager->isValidEntryId(entryId)) {
        g_ftManager->setFinal(entryId, 0);
        g_ftManager->getOwner(entryId)->setFinal(1, 1);
        OSReport(lbl_27_data_54660);
    }
}
