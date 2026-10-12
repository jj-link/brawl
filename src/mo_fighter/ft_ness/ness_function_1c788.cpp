#include <so/so_module_accesser.h>
#include <math.h>

extern "C" {
extern const float lbl_101_rodata_128[1] = {0.0f};
extern const float lbl_101_rodata_12C[1] = {57.29578f};
}

extern "C" void fn_101_1C788(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soPostureModule* posture = accesser->m_enumerationStart->m_postureModule;
    soLinkModule* link = accesser->m_enumerationStart->m_linkModule;
    if (link->isLink(5)) {
        Vec3f previous;
        previous.m_x = work->getFloat(0x21000002);
        previous.m_y = work->getFloat(0x21000003);
        previous.m_z = lbl_101_rodata_128[0];
        posture->setPos(&previous);
        Vec2f saved;
        saved.m_x = work->getFloat(0x21000000);
        saved.m_y = work->getFloat(0x21000001);
        work->setFloat(saved.m_x, 0x21000002);
        work->setFloat(saved.m_y, 0x21000003);
        Vec3f current = link->getParentModelNodeGlobalPosition(5, static_cast<u32>(0), true);
        work->setFloat(current.m_x, 0x21000000);
        work->setFloat(current.m_y, 0x21000001);
        Vec2f displacement;
        displacement.m_x = current.m_x - previous.m_x;
        displacement.m_y = current.m_y - previous.m_y;
        double dx = displacement.m_x;
        double dy = displacement.m_y;
        Vec3f rotation;
        rotation.m_x = lbl_101_rodata_12C[0] * static_cast<float>(atan2(-dy, dx));
        rotation.m_y = lbl_101_rodata_128[0];
        rotation.m_z = lbl_101_rodata_128[0];
        posture->setRot(&rotation, 0);
    }
}
