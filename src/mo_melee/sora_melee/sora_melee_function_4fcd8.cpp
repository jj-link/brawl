#include <types.h>
#include <so/event/so_event_system.h>
#include <so/event/so_event_manage_module_impl.h>
#include <gf/gf_task.h>
#pragma force_active on
extern "C" {
void* fn_27_46AE0(void*, int);
void fn_803F0D4C(void*, void* (*)(void*, int));
void __dla__FPv(void*);
void __dl__FPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_505E0(void*, int);
void fn_27_50588(void*, int);
void* __dt__23soEventManageModuleImplFv(void*, short);
void* __dt__6gfTaskFv(void*, short);
extern char lbl_27_data_4B94[];
extern char lbl_27_data_5288[];
extern int lbl_27_bss_B8;
}
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(short);
};
extern "C" void* fn_27_4FCD8(char* p, int flags) {
    if (p) {
        *(void**)(p + 0x3c) = lbl_27_data_4B94;
        fn_803F0D4C(*(void**)(p + 0x94), fn_27_46AE0);
        __dla__FPv(*(void**)(p + 0xa4));
        lbl_27_bss_B8 = 0;
        if (p + 0x8e8) {
            if (p + 0x8f4) {
                if (p + 0x904) {
                    __destroy_arr(p + 0x910, fn_27_505E0, 12, 255);
                }
            }
            if (p + 0x8e8) {
                if (p + 0x8e8) {
                    short id = *(short*)(p + 0x8ec);
                    *(void**)(p + 0x8e8) = lbl_27_data_5288;
                    if (id != -1) {
                        soEventSystem::getInstance()->getManager(id)->eraseUnit(*(short*)(p + 0x8ee));
                    }
                }
            }
        }
        __dt__23soEventManageModuleImplFv(p + 0x8d4, -1);
        if (p + 0xbc) {
            if (p + 0xd0) {
                __destroy_arr(p + 0xdc, fn_27_50588, 8, 255);
            }
        }
        __dt__6gfTaskFv(p, 0);
        if (flags > 0) __dl__FPv(p);
    }
    return p;
}