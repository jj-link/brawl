#include <wn/weapon.h>

extern "C" {
extern const float lbl_98_rodata_D0, lbl_98_rodata_C8;
Vec3f* fn_98_F5B0(Vec3f* result, float x, float y, float z);
void fn_98_184A0(StageObject* owner, Vec3f* position, unsigned int effectID);

static inline void requestPositionEffect(soModuleAccesser* accesser, Vec3f* position,
                                        unsigned int effectID) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    if (!work.isFlag(0x12000004)) {
        soEffectModule& effect = accesser->getEffectModule();
        Vec3f rotation;
        effect.req(static_cast<EfID>(effectID), position,
            fn_98_F5B0(&rotation, lbl_98_rodata_D0, lbl_98_rodata_D0, lbl_98_rodata_D0),
            lbl_98_rodata_C8, 0, -1);
        work.onFlag(0x12000004);
    }
}

void fn_98_18494(StageObject* owner, Vec3f* position) {
    fn_98_184A0(owner, position, 0x80007);
}

void fn_98_184A0(StageObject* owner, Vec3f* position, unsigned int effectID) {
    requestPositionEffect(owner->m_moduleAccesser, position, effectID);
}
}
