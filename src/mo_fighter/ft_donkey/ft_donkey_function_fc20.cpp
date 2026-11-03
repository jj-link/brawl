#include <so/so_value_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/item/so_item_manage_module_impl.h>
#pragma force_active on

struct DamageInfo {
    char pad[0xc];
    float value;
    char pad10[0x88];
    unsigned int id;
};

extern "C" int fn_27_63438(void*, float);
extern "C" float lbl_92_rodata_88;
extern "C" float lbl_92_rodata_8C;

extern "C" int fn_92_FC20(void*, soModuleAccesser* self, DamageInfo* info) {
    if (!self->m_enumerationStart->m_linkModule->isLinked(0))
        return 0;
    if (info->id == (unsigned int)self->m_enumerationStart->m_linkModule->getNodeTaskId(0))
        return 0;
    float value = info->value * soValueAccesser::getConstantFloat(self, 0x7d2, 0);
    if (fn_27_63438(self, value) < 3)
        return 1;
    if (self->m_enumerationStart->m_itemManageModule->isHaveItem(0))
        self->m_enumerationStart->m_itemManageModule->dropItem(lbl_92_rodata_88, lbl_92_rodata_8C, 0);
    return 0;
}