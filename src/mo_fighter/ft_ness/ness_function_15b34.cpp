#include <so/so_module_accesser.h>
#include <types.h>

class soCollisionAttackData;
class soCollisionLog;

extern "C" {
extern const unsigned char lbl_101_data_853C[], lbl_101_data_4330[];
extern const float lbl_101_rodata_A0, lbl_101_rodata_A8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DB0E8(void*, float, soCollisionAttackData*, u32, int,
                   soModuleAccesser*, soCollisionLog*);
}

extern "C" void fn_101_15B34(void* object, float power, soCollisionAttackData* attack,
                              u32 index, int kind, soModuleAccesser* accesser,
                              soCollisionLog* log) {
    fn_27_1DB0E8(object, power, attack, index, kind, accesser, log);
    soModuleAccesser* owner = *reinterpret_cast<soModuleAccesser**>(
        static_cast<unsigned char*>(object) + 0x60);
    if (owner->getStatusModule().getStatusKind() == 1) {
        unsigned char* fighter = static_cast<unsigned char*>(__dynamic_cast(
            &accesser->getStageObject(), 0x3c, lbl_101_data_853C, lbl_101_data_4330,
            static_cast<short>(1)));
        const float* parameters = *reinterpret_cast<const float**>(fighter + 0x23ac);
        float damage = accesser->getDamageModule().getDamage(0);
        float remaining = static_cast<float>(accesser->getWorkManageModule().getInt(0x10000004))
                        - damage * parameters[5];
        if (remaining < lbl_101_rodata_A8) {
            remaining = lbl_101_rodata_A0;
        }
        accesser->getWorkManageModule().setInt(static_cast<int>(remaining), 0x10000004);
    }
}
