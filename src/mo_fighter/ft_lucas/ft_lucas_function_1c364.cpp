#include <so/so_module_accesser.h>
#include <math.h>
#pragma force_active on

extern const float lbl_114_rodata_148;
extern const float lbl_114_rodata_14C;

extern "C" void fn_114_1C364(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soPostureModule* posture = &accesser->getPostureModule();
    soLinkModule* link = &accesser->getLinkModule();

    if (link->isLink(5)) {
        Vec3f pos;
        pos.m_x = work->getFloat(0x21000002);
        pos.m_y = work->getFloat(0x21000003);
        pos.m_z = lbl_114_rodata_148;
        posture->setPos(&pos);

        Vec2f prev;
        prev.m_x = work->getFloat(0x21000000);
        prev.m_y = work->getFloat(0x21000001);
        work->setFloat(prev.m_x, 0x21000002);
        work->setFloat(prev.m_y, 0x21000003);

        Vec3f parent = link->getParentModelNodeGlobalPosition(5, (u32)0, true);
        work->setFloat(parent.m_x, 0x21000000);
        work->setFloat(parent.m_y, 0x21000001);

        Vec2f diff;
        diff.m_x = parent.m_x - pos.m_x;
        diff.m_y = parent.m_y - pos.m_y;

        Vec3f rot;
        rot.m_x = lbl_114_rodata_14C * atan2f(-diff.m_y, diff.m_x);
        rot.m_y = lbl_114_rodata_148;
        rot.m_z = lbl_114_rodata_148;
        posture->setRot(&rot, 0);
    }
}
