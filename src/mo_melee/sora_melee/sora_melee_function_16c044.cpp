#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_2150;
void fn_8003DC64(Vec2f*, float, Vec2f*);
}

struct DamageData {
    char pad[0x30];
    float scale;
    float nx;
    float ny;
    char pad2[9];
    unsigned char flags;
};

extern "C" void fn_27_16C044(void*, soModuleAccesser* a) {
    DamageData* damage = (DamageData*)a->getDamageModule().getDamageLog();
    if (a->getStopModule().isDamage() == 1 && !((damage->flags >> 4) & 1) &&
        !a->getWorkManageModule().isFlag(0x12000037)) {
        unsigned char xFlick = a->getControllerModule().getFlickX();
        unsigned char yFlick = a->getControllerModule().getFlickY();
        int threshold = soValueAccesser::getConstantInt(a, 0x5a01, 0);
        if (xFlick < threshold || yFlick < threshold) {
            float x = a->getControllerModule().getStickX();
            float y = a->getControllerModule().getStickY();
            float limit = soValueAccesser::getConstantFloat(a, 0xc65, 0);
            float ysq = y*y;
            float xsq = x*x;
            float lsq = limit*limit;
            if (xsq + ysq >= lsq) {
                float scale = soValueAccesser::getConstantFloat(a, 0xc66, 0);
                Vec3f pos = a->getPostureModule().getPos();
                float amount = scale * damage->scale;
                Vec2f delta(amount*x, amount*y);
                if (((unsigned int)(damage->flags >> 6) & 1) == 1) {
                    if (damage->nx * delta.m_x + damage->ny * delta.m_y < lbl_27_rodata_2150)
                        delta.m_y = lbl_27_rodata_2150;
                    fn_8003DC64(&delta, (float)atan2(-damage->nx, damage->ny), &delta);
                }
                float py = pos.m_y + delta.m_y;
                float px = pos.m_x + delta.m_x;
                float pz = pos.m_z;
                pos.m_y = py;
                pos.m_x = px;
                pos.m_z = pz;
                a->getPostureModule().setPos(&pos);
                a->getControllerModule().resetFlickX();
                a->getControllerModule().resetFlickY();
            }
        }
    }
}