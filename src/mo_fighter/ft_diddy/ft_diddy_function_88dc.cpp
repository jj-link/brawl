#include <so/so_module_accesser.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_27_12DCA8(void*);
}

extern "C" void fn_115_88DC(void* object) {
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (!(*reinterpret_cast<soModuleAccesser**>(storage + 0x60))
                 ->getStopModule().isStop()) {
            if ((*reinterpret_cast<soModuleAccesser**>(storage + 0x60))
                    ->getWorkManageModule().isFlag(0x1200003d)) {
                (*reinterpret_cast<soModuleAccesser**>(storage + 0x60))
                    ->getWorkManageModule().addInt(1, 0x10000040);

                soModuleAccesser* accesser =
                    *reinterpret_cast<soModuleAccesser**>(storage + 0x60);
                soWorkManageModule* work = &accesser->getWorkManageModule();
                int threshold =
                    getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                        accesser, 0x5dc1, 0);

                if (work->getInt(0x10000040) >= threshold) {
                    (*reinterpret_cast<soModuleAccesser**>(storage + 0x60))
                        ->getWorkManageModule().offFlag(0x1200003d);
                    (*reinterpret_cast<soModuleAccesser**>(storage + 0x60))
                        ->getWorkManageModule().setInt(0, 0x10000040);
                }
            }
        }
    }

    fn_27_12DCA8(object);
}
