#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_122_rodata_A0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
int fn_27_8E8DC(float);
void fn_27_1D9FF8(void*);
}
extern "C" void fn_122_17CB4(void* self) {
    unsigned char* s = (unsigned char*)self;
    if (!lbl_27_bss_F0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if (!(*(soModuleAccesser**)(s+0x60))->getStopModule().isStop()) {
            if ((*(soModuleAccesser**)(s+0x60))->getWorkManageModule().getInt(0x10000005) > 0) {
                (*(soModuleAccesser**)(s+0x60))->getWorkManageModule().decInt(0x10000005);
                if ((*(soModuleAccesser**)(s+0x60))->getWorkManageModule().getInt(0x10000005) <= 0)
                    (*(soModuleAccesser**)(s+0x60))->getStatusModule().changeStatusRequest(6, *(soModuleAccesser**)(s+0x60));
            }
        }
    }
    if ((*(soModuleAccesser**)(s+0x60))->getStatusModule().getStatusKind() == 4) {
        if ((*(soModuleAccesser**)(s+0x60))->getLinkModule().isModelConstraint()) {
            Vec3f pos = (*(soModuleAccesser**)(s+0x60))->getLinkModule().getModelConstraintTargetNodePosition();
            (*(soModuleAccesser**)(s+0x60))->getPostureModule().setPos(&pos);
            float value = (*(soModuleAccesser**)(s+0x60))->getLinkModule().getParentDamagePowerMax(3);
            if (value > lbl_122_rodata_A0) {
                if (fn_27_8E8DC(value / *(float*)(*(unsigned char**)(s+0x23e8)+0x18)))
                    (*(soModuleAccesser**)(s+0x60))->getStatusModule().changeStatusForce(0, *(soModuleAccesser**)(s+0x60));
            }
        }
    }
    fn_27_1D9FF8(self);
}