#pragma force_active on
#include <it/it_manager.h>
#include <mt/mt_vector.h>

extern "C" {
extern const float lbl_27_rodata_46C8[];
float fn_27_28FB1C(BaseItem*);
void fn_27_28FF84(Vec3f*, BaseItem*, float, float);
void fn_27_28F1D4(BaseItem*, BaseItem*);
void fn_27_28F9BC(BaseItem*, BaseItem*);
void mtSinCosf__FfPfPf(float, float*, float*);
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

extern "C" int fn_27_2996FC(void* unused, BaseItem* item, float farg0, float farg1) {
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule* work = item->m_moduleAccesser->m_enumerationStart->m_workManageModule;
    int count = work->getInt(0x10000000);
    if (count <= 0) {
        item->changeMotion(7, false);
        return 0;
    }
    float t = fn_27_28FB1C(item) - k[0];
    if (t < k[5]) {
        t = k[5];
    }
    Vec3f v48;
    Vec3f pos;
    Vec3f vel;
    v48.m_x = k[17] * t;
    v48.m_y = k[5];
    v48.m_z = k[5];
    Vec3f hit = item->m_moduleAccesser->m_enumerationStart->m_modelModule->getNodeGlobalPosition(4, &v48, false, false);
    pos.m_x = hit.m_x;
    pos.m_y = hit.m_y;
    pos.m_z = k[5];
    Vec3f safe;
    fn_27_28FF84(&safe, item, hit.m_y, hit.m_x);
    BaseItem* child = itManager::getInstance()->createItem(&safe, &pos, farg0, (itKind)0xE, 0, item->m_taskId, 0, 0, 0xffff, 0, 0xffff);
    if (child != NULL) {
        child->m_moduleAccesser->m_enumerationStart->m_groundModule->setTestCollStop(true, 0);
        fn_27_28F1D4(child, item);
        fn_27_28F9BC(child, item);
        float val = work->getFloat(0x11000000);
        vel.m_x = k[5];
        vel.m_y = k[5];
        vel.m_z = k[5];
        mtSinCosf__FfPfPf(k[12] + -(k[2] * farg1), &vel.m_y, &vel.m_x);
        float tmp = val * farg0;
        vel.m_x = vel.m_x * tmp;
        vel.m_y = vel.m_y * val;
        KM* km = (KM*)child->m_moduleAccesser->m_enumerationStart->m_kineticModule;
        km->setSpeed(&vel.m_x, child->m_moduleAccesser);
        if (count == 1) {
            child->changeMotion(1, false);
        }
        count -= 1;
        if (count <= 0) {
            count = 0;
        }
    }
    work->setInt(count, 0x10000000);
    return count;
}
