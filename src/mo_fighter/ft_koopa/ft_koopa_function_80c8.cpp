#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_12DCA8(void*);
float fn_102_8330(float, float, float);
}

#define KOOPA_ACCESSER(obj) (*reinterpret_cast<soModuleAccesser**>(static_cast<unsigned char*>(obj) + 0x60))

extern "C" void fn_102_80C8(void* object) {
    fn_27_12DCA8(object);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if (!KOOPA_ACCESSER(object)->getStopModule().isStop()) {
            float f31 = KOOPA_ACCESSER(object)->getWorkManageModule().getFloat(0x11000014);
            float f30 = KOOPA_ACCESSER(object)->getWorkManageModule().getFloat(0x11000013);
            if (KOOPA_ACCESSER(object)->getStatusModule().getStatusKind() != 0x112) {
                f31 += soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFAA, 0);
                f30 += soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFAB, 0);
            } else if (KOOPA_ACCESSER(object)->getWorkManageModule().getInt(0x20000002) == 1) {
                f31 -= soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFAC, 0);
                f30 -= soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFAD, 0);
            }
            float f29 = soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFA7, 0);
            float f3 = soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFA6, 0);
            float r = fn_102_8330(f31, f29, f3);
            KOOPA_ACCESSER(object)->getWorkManageModule().setFloat(r, 0x11000014);
            float g29 = soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFA9, 0);
            float g3 = soValueAccesser::getConstantFloat(KOOPA_ACCESSER(object), 0xFA8, 0);
            float r2 = fn_102_8330(f30, g29, g3);
            KOOPA_ACCESSER(object)->getWorkManageModule().setFloat(r2, 0x11000013);
        }
    }
}
