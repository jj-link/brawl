#include <so/so_module_accesser.h>
#include <snd/snd_system.h>

extern "C" {
extern const float lbl_117_rodata_98;
void fn_80076274(sndSystem*, int);
}

extern "C" void fn_117_11698(void*, soModuleAccesser* accesser, int nextStatus) {
    switch (nextStatus) {
    case 0x116:
        return;
    case 0x139: {
        Vec3f rotation = accesser->getModelModule().getNodeRotate(7);
        float z = rotation.m_z;
        Vec3f adjusted;
        adjusted.m_x = rotation.m_x;
        adjusted.m_y = lbl_117_rodata_98;
        adjusted.m_z = z;
        accesser->getModelModule().setNodeRotate(7, &adjusted);
        break;
    }
    case 0x138:
        break;
    default:
        if (accesser->getWorkManageModule().getInt(0x20000007) >= 0)
            fn_80076274(g_sndSystem, 0x1b49);
        accesser->getEffectModule().removeCommon(0x26);
        accesser->getEffectModule().removeCommon(0x25);
        accesser->getCollisionHitModule().cancelXluGlobal(0);
        break;
    }
}
