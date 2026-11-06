#include <it/it_manager.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_46C8[];
void fn_27_28FF84(Vec3f*, BaseItem*);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
void fn_27_28E108(BaseItem*, Vec3f*, float, float);
}
extern "C" int fn_27_299D34(void*, BaseItem* item, int kind, float lr) {
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) return 0;
    soModuleEnumeration* enumeration = *(soModuleEnumeration**)((char*)item + 0x1a4);
    if (enumeration->m_statusModule->getStatusKind() != 2) return 0;
    Vec3f pos = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(2, false);
    pos.m_z = k[5];
    Vec3f speed;
    Vec3f safe;
    fn_27_28FF84(&safe, item);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, lr, (itKind)0x3b, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child) {
        child->m_moduleAccesser->m_enumerationStart->m_groundModule->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        float scale = k[0];
        speed.m_x = k[18] * lr;
        speed.m_y = k[5];
        speed.m_z = k[5];
        switch (kind) {
        case 0:
            scale = item->getParamFloat(0x1af7);
            speed.m_x *= item->getParamFloat(0x1af5);
            break;
        case 1:
            scale = item->getParamFloat(0x1af8);
            speed.m_x *= item->getParamFloat(0x1af6);
            break;
        }
        fn_27_28E108(child, &speed, lr, scale);
        if (count > 0) {
            --count;
            if (count == 0) {
                item->m_moduleAccesser->m_enumerationStart->m_motionModule->addOtherAnim(k[5], k[0], 0, 8, false);
                item->m_moduleAccesser->m_enumerationStart->m_motionModule->setOtherAnimRate(k[5], 0);
                item->m_moduleAccesser->m_enumerationStart->m_motionModule->setOtherAnimFrame(k[0], 0);
            }
        }
    }
    work->setInt(count, 0x10000000);
    return count;
}