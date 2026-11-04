#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_119_rodata_B8;
extern const float lbl_119_rodata_BC;
}

extern "C" void fn_119_139CC(void*, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    switch (accesser->getStatusModule().getStatusKind()) {
    case 3:
    Vec3f pos = accesser->getPostureModule().getPos();
    float a = accesser->getWorkManageModule().getFloat(0x21000002);
    float b = accesser->getWorkManageModule().getFloat(0x21000003);
    float c = accesser->getWorkManageModule().getFloat(0x21000004);
    float x;
    if (accesser->getWorkManageModule().isFlag(0x22000000)) {
        x = accesser->getWorkManageModule().getFloat(0x21000006);
        x += accesser->getWorkManageModule().getFloat(0x21000005);
        accesser->getWorkManageModule().setFloat(x, 0x21000006);
    } else {
        pos.m_x += accesser->getWorkManageModule().getFloat(0x21000005);
        x = pos.m_x;
    }
    pos.m_y = c + (x * (a * x) + b * x);
    accesser->getPostureModule().setPos(&pos);
    Vec3f rot = accesser->m_enumerationStart->m_modelModule->getNodeRotate(3);
    float v = accesser->getWorkManageModule().getFloat(0x21000007);
    v += params->getParamFloat(accesser, 0xFA0, 0);
    if (v > lbl_119_rodata_B8)
        v -= lbl_119_rodata_B8;
    else if (v < lbl_119_rodata_BC)
        v += lbl_119_rodata_B8;
    rot.m_x = v;
    accesser->m_enumerationStart->m_modelModule->setNodeRotate(3, &rot);
    accesser->getWorkManageModule().setFloat(v, 0x21000007);
    }
}