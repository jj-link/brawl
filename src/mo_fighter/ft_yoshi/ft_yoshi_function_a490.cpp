#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Class_8DBC {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16C80();
    virtual void fn_95_17664();
    virtual void fn_95_1765C();
    virtual void fn_95_17654();
    virtual void fn_95_1764C();
    virtual void fn_95_17644();
    virtual void fn_95_1763C();
    virtual void fn_95_17634();
    virtual void fn_95_1762C();
    virtual void fn_95_17624();
    virtual void fn_95_1761C();
    virtual void fn_95_17614();
    virtual void fn_95_1760C();
    virtual void fn_95_175BC();
    virtual void fn_95_17604();
    virtual void fn_95_175F4();
    virtual void fn_95_175E4();
    virtual bool fn_95_175D4(int);
};

extern "C" {
extern const char lbl_95_data_2E5C[], lbl_95_data_36D8[];
extern const float lbl_95_rodata_10, lbl_95_rodata_4;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_95_16E70(void*, unsigned int, int, float, const Vec3f*);
}

extern "C" int fn_95_A490(void* object, soModuleAccesser* accesser) {
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(4));
    const float* parameters = *reinterpret_cast<const float**>(reinterpret_cast<char*>(data) + 0x84);
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c,
        lbl_95_data_2E5C, lbl_95_data_36D8, short(1)));
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(1, false);
    float facing;
    if (static_cast<Class_8DBC*>(accesser->m_enumerationStart->m_generateArticleManageModule)->fn_95_175D4(0))
        facing = lbl_95_rodata_10;
    else
        facing = lbl_95_rodata_4;
    position.m_x += parameters[1] * facing;
    position.m_y += parameters[2];
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_95_16E70(object, taskId, ownerId, facing, &position);
    return 1;
}