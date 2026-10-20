#include <it/it_manager.h>
#pragma force_active on

extern itManager* lbl_27_bss_6A34;

itManager* itManager::getInstance()
{
    return lbl_27_bss_6A34;
}
