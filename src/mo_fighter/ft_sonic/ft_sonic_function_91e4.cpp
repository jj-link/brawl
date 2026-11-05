#include <memory.h>
#include <mt/mt_vector.h>
#include <nw4r/math.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

#define SONIC_ACCESS(p) (*reinterpret_cast<soModuleAccesser**>(reinterpret_cast<char*>(p) + 0x60))

class KineticEnergyView {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long long getSpeedBits();
};

extern "C" {
extern const char lbl_123_data_1708[], lbl_123_data_1760[];
extern const float lbl_123_rodata_8;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_135468(void*);
void fn_123_9574(Vec2f&, const Vec2f&);
}

extern "C" int fn_123_91E4(void* self) {
    fn_27_135468(self);
    if (SONIC_ACCESS(self)->getStatusModule().getStatusKind() == 0x11E) {
        if (SONIC_ACCESS(self)->getWorkManageModule().isFlag(0x22000011)) {
            SONIC_ACCESS(self)->getWorkManageModule().offFlag(0x22000011);
            SONIC_ACCESS(self)->getWorkManageModule().subInt(
                soValueAccesser::getConstantInt(SONIC_ACCESS(self), 0x5dc9, 0), 0x20000003);
            SONIC_ACCESS(self)->getWorkManageModule().subFloat(
                soValueAccesser::getConstantFloat(SONIC_ACCESS(self), 0xfca, 0), 0x21000005);
            if (SONIC_ACCESS(self)->getWorkManageModule().getFloat(0x21000005) < lbl_123_rodata_8) {
                SONIC_ACCESS(self)->getWorkManageModule().setFloat(lbl_123_rodata_8, 0x21000005);
            }
            SONIC_ACCESS(self)->getWorkManageModule().subFloat(
                soValueAccesser::getConstantFloat(SONIC_ACCESS(self), 0xfca, 0), 0x21000004);
            if (SONIC_ACCESS(self)->getWorkManageModule().getFloat(0x21000004) < lbl_123_rodata_8) {
                SONIC_ACCESS(self)->getWorkManageModule().setFloat(lbl_123_rodata_8, 0x21000004);
            }
            KineticEnergyView* energy;
            if (SONIC_ACCESS(self)->getSituationModule().getKind() == 0) {
                energy = static_cast<KineticEnergyView*>(__dynamic_cast(
                    SONIC_ACCESS(self)->getKineticModule().getEnergy(3), 0, lbl_123_data_1708, lbl_123_data_1760, 0));
            } else {
                energy = static_cast<KineticEnergyView*>(__dynamic_cast(
                    SONIC_ACCESS(self)->getKineticModule().getEnergy(2), 0, lbl_123_data_1708, lbl_123_data_1760, 0));
            }
            if (energy == 0) {
                return 0;
            }
            Vec2f v;
            unsigned long long bits = energy->getSpeedBits();
            __memcpy(&v, &bits, sizeof(v));
            float ax = (float)(double)nw4r::math::FAbs(v.m_x);
            if (ax <= soValueAccesser::getConstantFloat(SONIC_ACCESS(self), 0xfca, 0)) {
                v.m_x = lbl_123_rodata_8;
            } else {
                soModuleAccesser* acc = SONIC_ACCESS(self);
                int sign = v.m_x < lbl_123_rodata_8 ? -1 : 1;
                float fsign = (float)sign;
                float thr = soValueAccesser::getConstantFloat(acc, 0xfca, 0);
                v.m_x -= thr * fsign;
            }
            fn_123_9574(*reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 8), v);
        }
    }
    return 0;
}
