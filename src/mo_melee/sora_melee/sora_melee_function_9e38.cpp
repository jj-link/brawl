#pragma opt_loop_invariants off
#include <so/model/so_model_module_impl.h>
#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
extern const float lbl_27_rodata_300;
void soModelModuleImpl::clearNodeSetUp() {
    void* node = 0;
    while ((node = fn_8015C1B0((char*)this + 0x3c, node)) != 0) {
        *(void**)((char*)node + 0x28) = 0;
    }
    clearSetUpMtx();
    if (lbl_27_rodata_300 != *(float*)((char*)this + 0x4c)) {
        Vec3f scale(lbl_27_rodata_300, lbl_27_rodata_300, lbl_27_rodata_300);
        setNodeScale(0, &scale);
    }
}