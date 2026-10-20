#include <st/st_melee.h>
#pragma force_active on

void stMelee::getItemGenPac(gfArchive** archive) {
    *archive = &m_itemSheetArchive;
}
