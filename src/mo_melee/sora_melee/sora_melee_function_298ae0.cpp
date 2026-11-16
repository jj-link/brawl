#include <it/it_manager.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_46DC;
extern const float lbl_27_rodata_46F4;
float fn_27_28FB1C(BaseItem*);
void fn_27_28FF84(Vec3f*, BaseItem*);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
int fn_27_28CCF0(BaseItem*, int);
double getParamFloat__8BaseItemFUl(BaseItem*, unsigned long);
}
struct KM {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void setSpeed(float*, void*);
};
extern "C" int fn_27_298AE0(void*, BaseItem* item, int maxLevel, float lr) {
    int level;
    int idx;
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) {
        item->changeMotion(7, false);
        return 0;
    }
    Vec3f pos = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(1, false);
    float fac = fn_27_28FB1C(item);
    float dx = lbl_27_rodata_46F4 * lr;
    pos.m_x += dx * fac;
    pos.m_z = lbl_27_rodata_46DC;
    Vec3f sp;
    Vec3f safe;
    fn_27_28FF84(&safe, item);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, lr, (itKind)0x3e, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child) {
        child->m_moduleAccesser->m_enumerationStart->m_groundModule->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        if (maxLevel <= fn_27_28CCF0(item, 0x69ab)) {
            level = 0;
        } else if (maxLevel <= fn_27_28CCF0(item, 0x69ac) * 8) {
            level = (maxLevel / fn_27_28CCF0(item, 0x69ac)) + 1;
        } else {
            level = 9;
        }
        if (level >= 0 && level <= 9) {
            idx = level * 2;
            float speedX = (float)getParamFloat__8BaseItemFUl(item, idx + 0x1b8b);
            sp.m_y = lbl_27_rodata_46DC;
            sp.m_z = lbl_27_rodata_46DC;
            sp.m_x = speedX * lr;
            ((KM*)child->m_moduleAccesser->m_enumerationStart->m_kineticModule)->setSpeed((float*)&sp, child->m_moduleAccesser);
            child->m_moduleAccesser->m_enumerationStart->m_postureModule->setScale(item->getParamFloat(idx + 0x1b8a));
            child->m_moduleAccesser->m_enumerationStart->m_groundModule->setShapeFlag((soGroundShapeImpl::ShapeFlagId)1, true, 0);
            child->updateNodeSRT();
            child->changeMotion(level, false);
            count -= fn_27_28CCF0(item, level + 0x69ad);
            if (count <= 0) count = 0;
        }
    }
    work->setInt(count, 0x10000000);
    return count;
}