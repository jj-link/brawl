#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_112_rodata_8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_12DCA8(void*);
}

#define FT_ACCESSER(obj) (*reinterpret_cast<soModuleAccesser**>(static_cast<unsigned char*>(obj) + 0x60))

extern "C" void fn_112_9758(void* object) {
    fn_27_12DCA8(object);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        float f31 = FT_ACCESSER(object)->getWorkManageModule().getFloat(0x11000013);
        f31 += soValueAccesser::getConstantFloat(FT_ACCESSER(object), 0xFB7, 0);
        int lim = soValueAccesser::getConstantInt(FT_ACCESSER(object), 0x5DC3, 0);
        if (f31 > (float)lim) {
            f31 = (float)lim;
        }
        FT_ACCESSER(object)->getWorkManageModule().setFloat(f31, 0x11000013);
        FT_ACCESSER(object)->getWorkManageModule().setFloat(lbl_112_rodata_8, 0x11000015);
        int kind = FT_ACCESSER(object)->getStatusModule().getStatusKind();
        if (kind != 0x11F && (kind >= 0x11F || kind != 0x115)) {
            float g = FT_ACCESSER(object)->getWorkManageModule().getFloat(0x11000014);
            g += soValueAccesser::getConstantFloat(FT_ACCESSER(object), 0xFBC, 0);
            if (g > soValueAccesser::getConstantFloat(FT_ACCESSER(object), 0xFBB, 0)) {
                g = soValueAccesser::getConstantFloat(FT_ACCESSER(object), 0xFBB, 0);
            }
            FT_ACCESSER(object)->getWorkManageModule().setFloat(g, 0x11000014);
        }
    }
    *(static_cast<unsigned char*>(object) + 0x297B5) = 0;
    *(static_cast<unsigned char*>(object) + 0x297B4) = 0;
}
