#include <it/it_manager.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_46C8[];
void fn_27_28FF84(Vec3f*, BaseItem*);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
void mtSinCosf__FfPfPf(float, float*, float*);
float randf__Fv();
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
extern "C" int fn_27_298EF8(void*, BaseItem* item, float lr) {
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) return 0;
    Vec3f pos = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(4, false);
    pos.m_z = k[5];
    float v[3];
    Vec3f safe;
    fn_27_28FF84(&safe, item);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, lr, (itKind)0x19, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child) {
        child->m_moduleAccesser->m_enumerationStart->m_groundModule->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        float a = child->getParamFloat(0x1482);
        float b = child->getParamFloat(0x1483);
        float s = a + (b - a) * randf__Fv();
        float c = child->getParamFloat(0x1484);
        float d = child->getParamFloat(0x1485);
        float r = (d - c) * randf__Fv();
        v[0] = k[5]; v[1] = k[5]; v[2] = k[5];
        mtSinCosf__FfPfPf(k[12] + -(k[2] * (c + r)), &v[1], &v[0]);
        v[0] = v[0] * (s * lr);
        v[1] = v[1] * s;
        KM* km = *(KM**)((char*)child->m_moduleAccesser->m_enumerationStart + 0x7c);
        km->setSpeed(v, child->m_moduleAccesser);
        if (--count <= 0) {
            count = 0;
            item->changeMotion(10, false);
        }
    }
    work->setInt(count, 0x10000000);
    return count;
}
