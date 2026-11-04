#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2E2534(void*, short);
void* fn_27_2E20E0(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_2DA6B8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void* __dt__16acCmdInterpreterFv(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void __dl__FPv(void*);
}
extern "C" void* fn_27_2E40B4(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x1F2C, -1);
            if (self + 0xCC) {
                if (self + 0x197C) {
                    if (self + 0x1E2C && self + 0x1E2C) {
                        __dt__16acCmdInterpreterFv(self + 0x1E2C, 0);
                    }
                    if (self + 0x1D00) {
                        if (self + 0x1DDC) {
                            __dt__16acCmdInterpreterFv(self + 0x1DDC, 0);
                        }
                    }
                    if (self + 0x1BD4) {
                        if (self + 0x1CB0) {
                            __dt__16acCmdInterpreterFv(self + 0x1CB0, 0);
                        }
                    }
                    if (self + 0x1AA8) {
                        if (self + 0x1B84) {
                            __dt__16acCmdInterpreterFv(self + 0x1B84, 0);
                        }
                    }
                    if (self + 0x197C) {
                        if (self + 0x1A58) {
                            __dt__16acCmdInterpreterFv(self + 0x1A58, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x1960) fn_27_C31CC(self + 0x1960, -1);
                    if (self + 0x1920) fn_27_63EBC(self + 0x1920, -1);
                    if (self + 0x1908) fn_27_5C674(self + 0x1908, -1);
                    fn_27_2DBA8C(self + 0x176C, -1);
                    fn_27_2DB610(self + 0x166C, -1);
                    fn_27_2E2534(self + 0x14A4, -1);
                    fn_27_1E09C4(self + 0x1400, -1);
                    if (self + 0x13CC) fn_27_A1E80(self + 0x13CC, -1);
                    if (self + 0x13B4) fn_27_5AE44(self + 0x13B4, -1);
                    if (self + 0x1250) fn_27_6A3D8(self + 0x1360, -1);
                    if (self + 0x11E8) fn_27_565F0(self + 0x11F4, -1);
                    if (self + 0x11DC) fn_27_6880C(self + 0x11E0, -1);
                    if (self + 0x11B4) __dt__16soStopModuleImplFv(self + 0x11B4, -1);
                    fn_27_2DAF88(self + 0xFE4, -1);
                    if (self + 0xF80) fn_27_B5324(self + 0xFA0, -1);
                    if (self + 0xF44) fn_27_3544C(self + 0xF44, -1);
                    if (self + 0xE9C) {
                        fn_27_25740(self + 0xEEC, -1);
                        if (self + 0xE9C) __destroy_arr(self + 0xEA8, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0xDE8) {
                        __dt__19soPostureModuleImplFv(self + 0xE24, -1);
                        if (self + 0xDE8 && self + 0xDE8) {
                            __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 1);
                        }
                    }
                    fn_27_2E20E0(self + 0xBDC, -1);
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