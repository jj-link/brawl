#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
extern "C" {
int fn_27_10B21C(ftManager*, int*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_100_data_18F8[];
extern char lbl_100_data_22AC[];
}
extern "C" void fn_100_FCE0() {
    int entries[8];
    int count = fn_27_10B21C(g_ftManager, entries);
    for (int i = 0; i < count; ++i) {
        int entry = entries[i];
        Fighter* fighter = g_ftManager->getFighter(entry, -1);
        if (fighter) {
            Fighter* obj = (Fighter*)__dynamic_cast(gfTask::getTask(fighter->m_taskId), 0x3c, lbl_100_data_18F8, lbl_100_data_22AC, 0);
            if (obj && soExternalValueAccesser::getSituationKind(obj) != 5)
                obj->setupEquipment();
        }
        fighter = g_ftManager->getSubFighter(entry);
        if (fighter) {
            Fighter* obj = (Fighter*)__dynamic_cast(gfTask::getTask(fighter->m_taskId), 0x3c, lbl_100_data_18F8, lbl_100_data_22AC, 0);
            if (obj && soExternalValueAccesser::getSituationKind(obj) != 5)
                obj->setupEquipment();
        }
    }
}