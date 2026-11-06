#include <so/so_module_accesser.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_5010[], lbl_94_data_5110[];
extern const float lbl_94_rodata_68;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_8CC84(void*);
}

struct SamusEvent : soLinkEventArgs {
    bool result;
    int node;
    float x, y, scale;
    SamusEvent(Vec3f& pos) : soLinkEventArgs(6) { scale = lbl_94_rodata_68; result = false; node = 0; x = pos.m_x; y = pos.m_y; }
};

extern "C" void fn_94_1A084(void*, soModuleAccesser* accesser) {
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    soLinkModule* link = modules->m_linkModule;
    soPostureModule* posture = modules->m_postureModule;
    int id = work->getInt(0x20000003);
    if (id != -1) {
        gfTask* task = gfTaskScheduler::getInstance()->getTask((u32)id);
        if (task && fn_27_8CC84(__dynamic_cast(task, 0x3c, lbl_94_data_5010, lbl_94_data_5110, (short)1)) && link->link(3, id)) {
            Vec3f pos = posture->getPos();
            SamusEvent event(pos);
            link->sendEventParents(3, event);
            if (event.result == 1) {
                link->setModelConstraintPosOrt(3, 0, event.node, 5, true);
            } else {
                work->onFlag(0x22000010);
                pos.m_x = event.x;
                pos.m_y = event.y;
                posture->setPos(&pos);
            }
        }
    }
}