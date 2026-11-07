#include <it/it_manager.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_46C8[];
float fn_27_28FB1C(BaseItem*);
void fn_27_28FF84(Vec3f*, BaseItem*);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
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
extern "C" int fn_27_29931C(void*, BaseItem* item, float lr) {
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) {
        item->changeMotion(8, false);
        return 0;
    }
    Vec3f pos = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(1, false);
    float fac = fn_27_28FB1C(item);
    float dx = k[13] * lr;
    dx *= fac;
    pos.m_x += dx;
    pos.m_y += k[14] * fac;
    pos.m_z = k[5];
    float speed[3];
    Vec3f safe;
    fn_27_28FF84(&safe, item);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, lr, (itKind)0x2d, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child) {
        child->m_moduleAccesser->m_enumerationStart->m_groundModule->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        speed[0] = k[11] * lr;
        speed[1] = k[5];
        speed[2] = k[5];
        KM* km = (KM*)child->m_moduleAccesser->m_enumerationStart->m_kineticModule;
        km->setSpeed(speed, child->m_moduleAccesser);
        if (--count <= 0) count = 0;
        item->changeMotion(7, false);
    }
    work->setInt(count, 0x10000000);
    return count;
}