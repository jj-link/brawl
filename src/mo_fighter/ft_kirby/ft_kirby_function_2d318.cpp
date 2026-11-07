#include <so/so_module_accesser.h>
#include <nw4r/math.h>
#pragma force_active on

struct KirbyEnergy {
    unsigned char padding[5];
    signed char flags;
    unsigned char padding2[2];
    float x;
    float y;
};

extern "C" {
extern const char lbl_96_data_CEF4[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_5B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_2D8B4(void*, soModuleAccesser*);
}

extern "C" void fn_96_2D318(void* self, soModuleAccesser* accesser)
{
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0: {
        if (accesser->getWorkManageModule().isFlag(0x22000000) == 0) {
            return;
        }
        KirbyEnergy* energy = static_cast<KirbyEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0, lbl_96_data_CEF4, lbl_96_data_5E00, 1));
        float scale = accesser->getLinkModule().getParentScale(1);
        float f30 = accesser->getWorkManageModule().getFloat(0x21000000);
        float f31 = scale * accesser->getWorkManageModule().getFloat(0x21000001);
        Vec3f linkPos = accesser->getLinkModule().getParentModelNodeGlobalPosition(1, (u32)0, false);
        Vec3f posturePos = accesser->getPostureModule().getPos();
        Vec2f speed;
        float dist = nw4r::math::FAbs(linkPos.m_x - posturePos.m_x);
        if (dist < f31) {
            float d = f31 - dist;
            if (f30 > d) {
                f30 = d;
            }
            speed.m_x = f30;
            speed.m_y = lbl_96_rodata_5B0[0];
            energy->x = speed.m_x;
            energy->y = speed.m_y;
            energy->flags |= 0x80;
            return;
        }
        accesser->getWorkManageModule().offFlag(0x22000000);
        accesser->getWorkManageModule().onFlag(0x22000002);
        energy->flags &= ~0x80;
        break;
    }
    case 1:
    case 2:
    case 3:
    case 4:
        fn_96_2D8B4(self, accesser);
        break;
    }
}
