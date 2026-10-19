#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" bool fn_96_E110(Fighter* fighter) {
    if (fighter->m_moduleAccesser->getStatusModule().getStatusKind() >= 0x133
        && fighter->m_moduleAccesser->getStatusModule().getStatusKind() <= 0x1bf)
        return true;
    return false;
}
