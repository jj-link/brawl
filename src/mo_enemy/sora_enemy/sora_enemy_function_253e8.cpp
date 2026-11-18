#include <em/em_area_module_impl.h>
#pragma force_active on

extern "C" {
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_534C(Vec3f*, const Vec3f&);

void fn_41_253E8(soModuleAccesser* acc, int index) {
    char* area = (char*)__dynamic_cast(
        acc->m_enumerationStart->m_areaModule, 0,
        __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);

    if (index == 8) {
        for (index = 0; index < 8; index++) {
            if (emAreaModuleImpl::isExistTarget(acc, index)) {
                fn_41_534C(
                    (Vec3f*)(area + 0x4a8 + index * 12),
                    emAreaModuleImpl::getTargetPos(acc, index, false));
                fn_41_534C(
                    (Vec3f*)(area + 0x508 + index * 12),
                    emAreaModuleImpl::getTargetPos(acc, index, true));
            }
        }
    } else {
        if (index > -1 && index < 8) {
            goto update_target;
        }
        return;

    update_target:
        fn_41_534C(
            (Vec3f*)(area + 0x4a8 + index * 12),
            emAreaModuleImpl::getTargetPos(acc, index, false));
        fn_41_534C(
            (Vec3f*)(area + 0x508 + index * 12),
            emAreaModuleImpl::getTargetPos(acc, index, true));
    }
}
}
