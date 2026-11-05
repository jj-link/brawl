#include <ft/fighter.h>
#include <so/so_value_accesser.h>

#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_96_data_B62C[];
extern const char lbl_96_data_B688[];
extern const char lbl_96_data_6024[];
extern const char lbl_96_data_68D8[];
extern const float lbl_96_rodata_78;
}

struct KirbyEatItemEventArgs : soLinkEventArgs {
    BaseItem* m_item;
    Vec3f m_pos;
    float m_value;
    bool m_flag;

    KirbyEatItemEventArgs(BaseItem* item, const Vec3f& pos)
        : soLinkEventArgs(-1), m_item(item), m_pos(pos),
          m_value(lbl_96_rodata_78), m_flag(false) {}
};

inline BaseItem* getKirbyItem(const soItemInfo& info) {
    return info.m_item;
}

extern "C" void fn_96_163E0(void*, soModuleAccesser* accesser) {
    if (!accesser->getWorkManageModule().isFlag(0x2200001C)) {
        if (accesser->getWorkManageModule().isFlag(0x22000013)) {
            soItemManageModule* items = static_cast<soItemManageModule*>(
                __dynamic_cast(
                    accesser->m_enumerationStart->m_itemManageModule,
                    0, lbl_96_data_B62C, lbl_96_data_B688, 1));

            for (int i = 3; i < 7; i++) {
                if (items->isHaveItem(i)) {
                    items->setHaveItemVisibility(0, i);
                }
            }

            accesser->getWorkManageModule().offFlag(0x22000013);
        }

        if (accesser->getWorkManageModule().isFlag(0x22000014)) {
            soItemManageModule* items = static_cast<soItemManageModule*>(
                __dynamic_cast(
                    accesser->m_enumerationStart->m_itemManageModule,
                    0, lbl_96_data_B62C, lbl_96_data_B688, 1));

            Fighter* fighter = static_cast<Fighter*>(
                __dynamic_cast(
                    accesser->m_stageObject, 0x3C,
                    lbl_96_data_6024, lbl_96_data_68D8, 1));

            for (int i = 3; i < 7; i++) {
                if (items->isHaveItem(i)) {
                    soItemInfo info;
                    items->getHaveItemInfo(&info, i);

                    float damage = accesser->getDamageModule().getDamage(0);
                    float change = lbl_96_rodata_78;

                    if (info.m_trait.m_mask & 0x20B0) {
                        items->useItem(static_cast<u32>(i));
                    } else if (info.m_trait.m_mask & 0x8000) {
                        change = soValueAccesser::getConstantFloat(
                            accesser, 0xFAA, 0);
                    } else if (
                        damage - soValueAccesser::getConstantFloat(
                            accesser, 0xFAB, 0) < lbl_96_rodata_78) {
                        change = -damage;
                    } else {
                        change = -soValueAccesser::getConstantFloat(
                            accesser, 0xFAB, 0);
                    }

                    Vec3f pos = accesser->getModelModule()
                                    .getNodeGlobalPosition(0x196, false);

                    KirbyEatItemEventArgs args(getKirbyItem(info), pos);
                    fighter->eatItem(
                        reinterpret_cast<soLinkTouchItemEventArgs*>(&args));

                    accesser->getDamageModule().addDamage(change, 0);
                    accesser->getItemManageModule().removeItem(i);
                }
            }

            accesser->getWorkManageModule().offFlag(0x22000014);
        }
    }
}
