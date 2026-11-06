#pragma force_active on
#include <types.h>
#include <so/event/so_event_system.h>

extern "C" {
extern char lbl_27_data_21018[];
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_BED74(void*, int);
void fn_27_B64B8(void*, int);
void fn_27_3132E8(void*, int);
void fn_27_313368(void*, int);
void fn_27_313AA0(void*, int);
void fn_27_313C08(void*, int);
void fn_27_313D94(void*, int);
void fn_27_A1E80(void*, int);
void __dt__22soControllerModuleImplFv(void*, short);
void fn_27_5B39C(void*, int);
void fn_27_6A3D8(void*, int);
void fn_27_565F0(void*, int);
void fn_27_689B0(void*, int);
void fn_27_7D898(void*, int);
void __dt__16soStopModuleImplFv(void*, short);
void fn_27_313F54(void*, int);
void fn_27_314010(void*, int);
void fn_27_B5324(void*, int);
void fn_27_3544C(void*, int);
void fn_27_319E9C(void*, int);
void fn_27_2E888(void*, int);
void __dt__19soPostureModuleImplFv(void*, short);
void fn_27_25290(void*, int);
void fn_27_3140AC(void*, int);
void fn_27_314180(void*, int);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_314200(void*, int);
}

extern "C" void* fn_27_31815C(char* self, int flag) {
    if (self) {
        if (self + 0x4864) {
            if (self + 0x4864) {
                s16 mgr = *(s16*)(self + 0x4868);
                *(void**)(self + 0x4864) = lbl_27_data_21018;
                if (soEventSystem::getInstance()->getInstanceManager().isContain(mgr) == 1) {
                    soEventSystem::getInstance()->getManager(*(s16*)(self + 0x4868))
                        ->eraseObserver(*(s16*)(self + 0x486A), *(s16*)(self + 0x486C));
                }
                *(s16*)(self + 0x486C) = -1;
                *(s16*)(self + 0x4868) = -1;
            }
        }
        if (self) {
            if (self + 0xCC) {
                if (self + 0x4188) {
                    if (self + 0x4734) {
                        if (self + 0x4810) __dt__16acCmdInterpreterFv(self + 0x4810, 0);
                    }
                    if (self + 0x4638) {
                        if (self + 0x4638) __dt__16acCmdInterpreterFv(self + 0x4638, 0);
                    }
                    if (self + 0x450C) {
                        if (self + 0x45E8) __dt__16acCmdInterpreterFv(self + 0x45E8, 0);
                    }
                    if (self + 0x43E0) {
                        if (self + 0x44BC) __dt__16acCmdInterpreterFv(self + 0x44BC, 0);
                    }
                    if (self + 0x42B4) {
                        if (self + 0x4390) __dt__16acCmdInterpreterFv(self + 0x4390, 0);
                    }
                    if (self + 0x4188) {
                        if (self + 0x4264) __dt__16acCmdInterpreterFv(self + 0x4264, 0);
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x4144) fn_27_63EBC(self + 0x4144, -1);
                    if (self + 0x412C) fn_27_5C674(self + 0x412C, -1);
                    if (self + 0x3FD4) fn_27_BED74(self + 0x3FD4, -1);
                    if (self + 0x3F88) fn_27_B64B8(self + 0x3F88, -1);
                    fn_27_3132E8(self + 0x3DF0, -1);
                    fn_27_313368(self + 0x1E30, -1);
                    fn_27_313AA0(self + 0x1C5C, -1);
                    fn_27_313C08(self + 0x1A30, -1);
                    fn_27_313D94(self + 0x197C, -1);
                    if (self + 0x1948) fn_27_A1E80(self + 0x1948, -1);
                    if (self + 0x1924) {
                        if (self + 0x1928) __dt__22soControllerModuleImplFv(self + 0x1928, 0);
                    }
                    if (self + 0x18F4) fn_27_5B39C(self + 0x18F4, -1);
                    if (self + 0x1790) fn_27_6A3D8(self + 0x18A0, -1);
                    if (self + 0x1728) fn_27_565F0(self + 0x1734, -1);
                    if (self + 0x16E4) {
                        fn_27_689B0(self + 0x170C, -1);
                        if (self + 0x16E4) {
                            if (self + 0x16E4) __destroy_arr(self + 0x16F0, fn_27_7D898, 0x1C, 1);
                        }
                    }
                    if (self + 0x16BC) __dt__16soStopModuleImplFv(self + 0x16BC, -1);
                    fn_27_313F54(self + 0x13D8, -1);
                    fn_27_314010(self + 0x1064, -1);
                    if (self + 0x1000) fn_27_B5324(self + 0x1020, -1);
                    if (self + 0xFC4) fn_27_3544C(self + 0xFC4, -1);
                    if (self + 0xF18) {
                        fn_27_319E9C(self + 0xF68, -1);
                        if (self + 0xF18) __destroy_arr(self + 0xF24, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0xE64) {
                        __dt__19soPostureModuleImplFv(self + 0xEA0, -1);
                        if (self + 0xE64) {
                            if (self + 0xE64) __destroy_arr(self + 0xE70, fn_27_25290, 0x30, 1);
                        }
                    }
                    fn_27_3140AC(self + 0xC1C, -1);
                    fn_27_314180(self + 0xA20, -1);
                    if (self + 0x9F0) __dt__20soResourceModuleImplFv(self + 0xA08, -1);
                    if (self + 0x9C8) __dt__16soHeapModuleImplFv(self + 0x9C8, -1);
                    __dt__16soModuleAccesserFv(self + 0x8E8, -1);
                    fn_27_314200(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
