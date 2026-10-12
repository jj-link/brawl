#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_projectile_launch.h>

namespace {
// Narrow views of the team interfaces not represented by the shared headers.
class DededeArticleTeamValue {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getValue();
};
class DededeArticleTeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual DededeArticleTeamValue* getValue();
};
}

extern "C" {
extern const float lbl_117_rodata_110;
}

extern "C" bool fn_117_1FB20(Weapon* article, soModuleAccesser* accesser) {
    float facing = accesser->m_enumerationStart->m_postureModule->getLr();
    Vec3f position(lbl_117_rodata_110, lbl_117_rodata_110, lbl_117_rodata_110);
    Vec3f offset;
    offset.m_x = lbl_117_rodata_110;
    offset.m_y = accesser->m_enumerationStart->m_workManageModule->getFloat(0x2100000a);
    offset.m_z = accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000009);
    position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(1, &offset, false, false);
    float angle = accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000008);
    soResourceModule* resource = accesser->m_enumerationStart->m_resourceModule;
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    DededeArticleTeamModule* team = static_cast<DededeArticleTeamModule*>(accesser->m_enumerationStart->m_teamModule);
    fn_117_1C1FC(article, taskId, resource->getResourceIdAccesser()->getAnmResId(),
                  team->getValue()->getValue(), &position, facing, angle);
    return false;
}
