#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
extern const float lbl_117_rodata_90, lbl_117_rodata_94;
}

extern "C" void fn_117_11320(void*, soModuleAccesser* accesser) {
    fn_27_89DAC(3, accesser);
    fn_27_89DAC(1, accesser);
    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    fn_27_89DAC(0, accesser);
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        accesser->getCollisionHitModule().setXluGlobal(0);
        accesser->getWorkManageModule().setInt(-1, 0x20000007);
        break;
    case 0x138: {
        int duration = soValueAccesser::getConstantInt(accesser, 0x5dcc, 0) * 60;
        accesser->getWorkManageModule().setInt(duration, 0x20000002);
        if (accesser->getPostureModule().getLr() == lbl_117_rodata_90) {
            Vec3f rotation = accesser->getModelModule().getNodeRotate(7);
            float z = rotation.m_z;
            Vec3f adjusted;
            adjusted.m_x = rotation.m_x;
            adjusted.m_y = lbl_117_rodata_94;
            adjusted.m_z = z;
            accesser->getModelModule().setNodeRotate(7, &adjusted);
        }
        break;
    }
    }
}
