#include <em/em_area_module_impl.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern f32 lbl_41_rodata_DA0;
int fn_41_2A6F4(unsigned int flags, int bit);
f32 fn_41_24570(soModuleAccesser* acc, u32 target);
}

struct TargetSearchLike {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 v6(s32, s32);
};

struct EnemyOwner {
    char pad00[0x18];
    soModuleAccesser* acc;
    char pad1C[0x60 - 0x1C];
    s32 unk60;
};

extern "C" s32 fn_41_29BBC(EnemyOwner* self, s32 arg1, s32 arg2) {
    if (arg1 == -1) {
        return -1;
    }
    if (arg2 == 0) {
        return -1;
    }
    TargetSearchLike* search =
        reinterpret_cast<TargetSearchLike*>(self->acc->m_enumerationStart->m_targetSearchModule);
    s32 result = -1;
    f32 best = lbl_41_rodata_DA0;
    for (s32 i = 0; i < 8; i++) {
        if (fn_41_2A6F4(arg2, i) != 0 || (fn_41_2A6F4(arg2, 8) != 0 && i == self->unk60)) {
            if (emAreaModuleImpl::isExistTarget(self->acc, i) && search->v6(arg1, i)) {
                f32 d = fn_41_24570(self->acc, i);
                if (best > d) {
                    result = i;
                    best = d;
                }
            }
        }
    }
    return result;
}
