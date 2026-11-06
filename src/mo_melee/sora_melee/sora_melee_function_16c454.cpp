#include <so/so_value_accesser.h>
#include <ft/ft_audience_manager.h>
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

class ftAudienceSlotProbe {
public:
    virtual ~ftAudienceSlotProbe();
    virtual void activate();
    virtual void deactivate();
    virtual void reqHandclapDead(float, bool);
    virtual float correctCheerReaction(float, float);
    virtual void reqCallFgmStopCheer();
    virtual void unknownSlot(int, int);
};

extern "C" void fn_27_16C454(void*, soModuleAccesser* a, void*, u32 arg) {
    if (arg == 1) {
        DamageData* damage = (DamageData*)a->getDamageModule().getDamageLog();
        if (!((damage->flags >> 4) & 1)) {
            float x = a->getControllerModule().getStickX();
            float y = a->getControllerModule().getStickY();
            float limit = soValueAccesser::getConstantFloat(a, 0xc65, 0);
            float ysq = y * y;
            float xsq = x * x;
            float lsq = limit * limit;
            if (xsq + ysq >= lsq) {
                float scale = soValueAccesser::getConstantFloat(a, 0xc67, 0);
                Vec3f pos = a->getPostureModule().getPos();
                float amount = scale * damage->scale;
                Vec2f delta(amount * x, amount * y);
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
            }
        }
        ftAudienceSlotProbe* audience;
        int id = a->getWorkManageModule().getInt(0x1000003F);
        if (id != -1) {
            audience = (ftAudienceSlotProbe*)g_ftAudienceManager->m_audience;
            audience->unknownSlot(id, a->getWorkManageModule().getInt(0x10000000));
            a->getWorkManageModule().setInt(-1, 0x1000003F);
        }
    }
}
