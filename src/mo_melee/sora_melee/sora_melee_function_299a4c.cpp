#include <it/it_manager.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_46DC;
extern const float lbl_27_rodata_46C8;
void fn_27_28FF84(Vec3f*, BaseItem*);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
void fn_27_28E108(BaseItem*, Vec3f*, float, float);
}
extern "C" int fn_27_299A4C(void*, BaseItem* item, int kind, float lr) {
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) return 0;
    Vec3f pos = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(2, false);
    pos.m_z = lbl_27_rodata_46DC;
    Vec3f speed;
    Vec3f safe;
    fn_27_28FF84(&safe, item);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, lr, (itKind)0x30, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child) {
        soGroundModule* ground = child->m_moduleAccesser->m_enumerationStart->m_groundModule;
        ground->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        float scale = lbl_27_rodata_46C8;
        speed.m_x = lr * item->getParamFloat(0x189c);
        speed.m_y = lbl_27_rodata_46DC;
        speed.m_z = lbl_27_rodata_46DC;
        switch (kind) {
        case 0:
            scale = item->getParamFloat(0x189f);
            speed.m_x *= item->getParamFloat(0x189d);
            break;
        case 1:
            scale = item->getParamFloat(0x18a0);
            speed.m_x *= item->getParamFloat(0x189e);
            break;
        }
        fn_27_28E108(child, &speed, lr, scale);
        if (--count <= 0) count = 0;
        item->changeMotion(7, false);
    }
    work->setInt(count, 0x10000000);
    return count;
}