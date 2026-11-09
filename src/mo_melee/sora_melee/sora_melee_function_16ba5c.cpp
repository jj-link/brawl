#include <types.h>
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

class StateRaw {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15(soModuleAccesser* a);
    virtual void m16(soModuleAccesser* a);
};

class KineticRaw {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual unsigned char* m7(int index);
};

class SituationRaw {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(int keep);
};

class EffectRaw {
public:
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(int v);
};

extern "C" void fn_27_16BA5C(StateRaw* self, soModuleAccesser* a) {
    if (a->getWorkManageModule().isFlag(0x22000013) == 1) {
        DamageData* damage = (DamageData*)a->getDamageModule().getDamageLog();
        int count = a->getWorkManageModule().getInt(0x20000002);
        if (count > 0) {
            count -= 1;
            a->getWorkManageModule().setInt(count, 0x20000002);
        }
        if (count <= 0) {
            a->getWorkManageModule().offFlag(0x22000013);
            unsigned char* k = ((KineticRaw*)&a->getKineticModule())->m7(4);
            k[5] = k[5] | 0x80;
            if (a->getWorkManageModule().isFlag(0x22000014)) {
                unsigned char* k1 = ((KineticRaw*)&a->getKineticModule())->m7(1);
                k1[5] = k1[5] | 0x80;
            }
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
            ((SituationRaw*)&a->getSituationModule())->m8(0);
            self->m15(a);
            if (a->getWorkManageModule().isFlag(0x22000015) == 1) {
                a->getWorkManageModule().offFlag(0x22000015);
                int v = a->getWorkManageModule().getInt(0x20000003);
                ((EffectRaw*)&a->getEffectModule())->m21(v);
            }
            a->getWorkManageModule().offFlag(0x12000037);
        } else {
            if (!((damage->flags >> 4) & 1) && !a->getWorkManageModule().isFlag(0x12000037)) {
                unsigned char xFlick = a->getControllerModule().getFlickX();
                unsigned char yFlick = a->getControllerModule().getFlickY();
                int threshold = soValueAccesser::getConstantInt(a, 0x5a01, 0);
                if (xFlick < threshold || yFlick < threshold) {
                    float x = a->getControllerModule().getStickX();
                    float y = a->getControllerModule().getStickY();
                    float limit = soValueAccesser::getConstantFloat(a, 0xc65, 0);
                    float ysq = y * y;
                    float xsq = x * x;
                    float lsq = limit * limit;
                    if (xsq + ysq >= lsq) {
                        float scale = soValueAccesser::getConstantFloat(a, 0xc66, 0);
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
                        a->getControllerModule().resetFlickX();
                        a->getControllerModule().resetFlickY();
                    }
                }
            }
        }
        return;
    }
    self->m16(a);
}
