#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <st/stage.h>
#include <mo_fighter/ft_dedede/ft_dedede_projectile_initialize.h>

extern "C" {
extern const char lbl_117_data_38CC[], lbl_117_data_4148[];
extern const float lbl_117_rodata_0[];
extern Stage* lbl_27_bss_5668;
void* __dynamic_cast(void*, int, const void*, const void*, short);
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
Vec3f* fn_117_8E7C(Vec3f*, const Vec3f*);
int fn_27_111364(ftOwner*);
}
float randf();

namespace {
inline void activateArticle(Weapon* article, soResourceModule* resource,
                            Fighter* fighter, const Vec3f* position, float direction,
                            int kind, bool thrown) {
    unsigned int taskId = fighter->m_taskId;
    fn_117_1F2EC(reinterpret_cast<DededeInitializeObject*>(article), taskId, resource->getResourceIdAccesser()->getEtcResId(),
                fn_27_111364(fighter->getOwner()), position, direction, kind, thrown);
}

inline bool activateDefaultWithTask(Weapon* article, soResourceModule* resource, unsigned int taskId,
                            Fighter* fighter, const float* constants, int kind) {
    Vec3f position;
    fn_117_1F2EC(reinterpret_cast<DededeInitializeObject*>(article), taskId, resource->getResourceIdAccesser()->getEtcResId(),
                fn_27_111364(fighter->getOwner()),
                fn_117_92AC(&position, constants[3], constants[3], constants[3]),
                constants[3], kind, false);
    return true;
}

inline bool activateDefault(Weapon* article, soResourceModule* resource,
                            Fighter* fighter, const float* constants, int kind) {
    return activateDefaultWithTask(article, resource, fighter->m_taskId, fighter, constants, kind);
}

}

extern "C" bool fn_117_8F34(Weapon* article, soModuleAccesser* accesser) {
    const float* constants = lbl_117_rodata_0;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_117_data_38CC, lbl_117_data_4148, short(1)));
    if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x1200003d)) {
        int thrownKind = accesser->m_enumerationStart->m_workManageModule->getInt(0x20000006);
        Vec3f position;
        fn_117_92AC(&position, constants[3], constants[3], constants[3]);
        if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x22000012)) {
            Vec3f offset;
            fn_117_92AC(&offset, constants[3], constants[3], constants[3]);
            if (accesser->m_enumerationStart->m_situationModule->getKind() == 2) {
                offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfc8, 0);
                offset.m_z = soValueAccesser::getConstantFloat(accesser, 0xfc7, 0) * accesser->m_enumerationStart->m_postureModule->getLr();
            } else {
                offset.m_y = soValueAccesser::getConstantFloat(accesser, 0xfc6, 0);
                offset.m_z = soValueAccesser::getConstantFloat(accesser, 0xfc5, 0) * accesser->m_enumerationStart->m_postureModule->getLr();
            }
            Vec3f globalPosition = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0, &offset, true, false);
            fn_117_8E7C(&position, &globalPosition);
        } else {
            lbl_27_bss_5668->getRandItemPos(&position);
        }
        float direction = constants[1];
        if (randf() < constants[5]) direction = constants[4];
        accesser->m_enumerationStart->m_workManageModule->offFlag(0x1200003d);
        activateArticle(article, accesser->m_enumerationStart->m_resourceModule,
                        fighter, &position, direction, thrownKind, true);
        return true;
    } else {
        int kind = accesser->m_enumerationStart->m_workManageModule->getInt(0x20000000);
        return activateDefault(article, accesser->m_enumerationStart->m_resourceModule,
            fighter, constants, kind);
    }
}
