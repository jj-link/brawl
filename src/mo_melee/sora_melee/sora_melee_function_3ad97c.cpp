#pragma force_active on
#include <types.h>
#include <so/event/so_event_system.h>

extern "C" {
extern char lbl_27_data_7310[];
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_C31CC(void*, int);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_2E2534(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
void fn_27_B4780(void*, int);
void fn_27_5B39C(void*, int);
void fn_27_6A3D8(void*, int);
void fn_27_565F0(void*, int);
void fn_27_6880C(void*, int);
void fn_27_2E70E0(void*, int);
void fn_27_2DAF88(void*, int);
void fn_27_B5324(void*, int);
void fn_27_25740(void*, int);
void fn_27_2E888(void*, int);
void __dt__19soPostureModuleImplFv(void*, short);
void fn_27_25290(void*, int);
void fn_27_3085C4(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2DA6B8(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
}

extern "C" void* fn_27_3AD97C(char* self, int flag) {
    if (self) {
        if (self + 0x21F0) {
            if (self + 0x21F0) {
                s16 mgr = *(s16*)(self + 0x21F4);
                *(void**)(self + 0x21F0) = lbl_27_data_7310;
                if (soEventSystem::getInstance()->getInstanceManager().isContain(mgr) == 1) {
                    soEventSystem::getInstance()->getManager(*(s16*)(self + 0x21F4))
                        ->eraseObserver(*(s16*)(self + 0x21F6), *(s16*)(self + 0x21F8));
                }
                *(s16*)(self + 0x21F8) = -1;
                *(s16*)(self + 0x21F4) = -1;
            }
        }
        if (self) {
            fn_27_1DBB60(self + 0x2174, -1);
            if (self + 0xCC) {
                if (self + 0x1BC4) {
                    if (self + 0x2074 && self + 0x2074) __dt__16acCmdInterpreterFv(self + 0x2074, 0);
                    if (self + 0x1F48) {
                        if (self + 0x2024) __dt__16acCmdInterpreterFv(self + 0x2024, 0);
                    }
                    if (self + 0x1E1C) {
                        if (self + 0x1EF8) __dt__16acCmdInterpreterFv(self + 0x1EF8, 0);
                    }
                    if (self + 0x1CF0) {
                        if (self + 0x1DCC) __dt__16acCmdInterpreterFv(self + 0x1DCC, 0);
                    }
                    if (self + 0x1BC4) {
                        if (self + 0x1CA0) __dt__16acCmdInterpreterFv(self + 0x1CA0, 0);
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x1BA8) fn_27_C31CC(self + 0x1BA8, -1);
                    if (self + 0x1B68) fn_27_63EBC(self + 0x1B68, -1);
                    if (self + 0x1B50) fn_27_5C674(self + 0x1B50, -1);
                    fn_27_2DBA8C(self + 0x19B4, -1);
                    fn_27_2DB610(self + 0x18A0, -1);
                    fn_27_2E2534(self + 0x16D8, -1);
                    fn_27_1E09C4(self + 0x1634, -1);
                    if (self + 0x1600) fn_27_A1E80(self + 0x1600, -1);
                    if (self + 0x15E4) fn_27_B4780(self + 0x15E8, -1);
                    if (self + 0x15B0) fn_27_5B39C(self + 0x15B0, -1);
                    if (self + 0x144C) fn_27_6A3D8(self + 0x155C, -1);
                    if (self + 0x13E4) fn_27_565F0(self + 0x13F0, -1);
                    if (self + 0x13D8) fn_27_6880C(self + 0x13DC, -1);
                    fn_27_2E70E0(self + 0x11D8, -1);
                    fn_27_2DAF88(self + 0x100C, -1);
                    if (self + 0xFA8) fn_27_B5324(self + 0xFC8, -1);
                    if (self + 0xEFC) {
                        fn_27_25740(self + 0xF4C, -1);
                        if (self + 0xEFC) __destroy_arr(self + 0xF08, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0xDE8) {
                        __dt__19soPostureModuleImplFv(self + 0xE84, -1);
                        if (self + 0xDE8) {
                            if (self + 0xDE8) __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 3);
                        }
                    }
                    fn_27_3085C4(self + 0xBDC, -1);
                    if (self + 0x9FC) __dt__17soModelModuleImplFv(self + 0xB10, -1);
                    if (self + 0x9CC) __dt__20soResourceModuleImplFv(self + 0x9E4, -1);
                    if (self + 0x9A4) __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                    fn_27_2DA6B8(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
