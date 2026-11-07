#include <ft/ft_common_data_accesser.h>
#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
};

extern "C" {
extern const char lbl_95_data_2E5C[], lbl_95_data_36D8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_95_1D630(void*, unsigned int, int, int, const Vec3f*, float, float);
}

extern "C" int fn_95_ABC4(void* object, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c,
        lbl_95_data_2E5C, lbl_95_data_36D8, short(1)));
    ftData* data = g_ftCommonDataAccesser.getData(static_cast<ftKind>(4));
    const float* parameters = *reinterpret_cast<const float**>(reinterpret_cast<char*>(data) + 0x88);
    float facing = accesser->m_enumerationStart->m_postureModule->getLr();
    Vec3f position = accesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(0x26, false);
    position.m_x += parameters[20] * facing;
    position.m_y += parameters[21];
    taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_95_1D630(object, taskId, 0xffff, ownerId, &position, facing, parameters[19]);
    return 0;
}