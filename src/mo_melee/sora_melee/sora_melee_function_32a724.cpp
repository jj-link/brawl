#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_32A9F4(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* __dt__22soControllerModuleImplFv(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_32AB80(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_2DA6B8(void*, short);
void* fn_27_1D81C8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}
extern "C" void* fn_27_32A724(char* self, int flag) {
    if (self) {
        fn_27_1DBB60(self + 0x1F68, -1);
        if (self + 0xCC) {
            if (self + 0x19B8) {
                if (self + 0x1E68 && self + 0x1E68)
                    __dt__16acCmdInterpreterFv(self + 0x1E68, 0);
                if (self + 0x1D3C) {
                    if (self + 0x1E18) __dt__16acCmdInterpreterFv(self + 0x1E18, 0);
                }
                if (self + 0x1C10) {
                    if (self + 0x1CEC) __dt__16acCmdInterpreterFv(self + 0x1CEC, 0);
                }
                if (self + 0x1AE4) {
                    if (self + 0x1BC0) __dt__16acCmdInterpreterFv(self + 0x1BC0, 0);
                }
                if (self + 0x19B8) {
                    if (self + 0x1A94) __dt__16acCmdInterpreterFv(self + 0x1A94, 0);
                }
            }
            if (self + 0xCC) {
                if (self + 0x199C) fn_27_C31CC(self + 0x199C, -1);
                if (self + 0x195C) fn_27_63EBC(self + 0x195C, -1);
                if (self + 0x1944) fn_27_5C674(self + 0x1944, -1);
                fn_27_2DBA8C(self + 0x17A8, -1);
                fn_27_2DB610(self + 0x1694, -1);
                fn_27_32A9F4(self + 0x14C4, -1);
                fn_27_1E09C4(self + 0x1420, -1);
                if (self + 0x13EC) fn_27_A1E80(self + 0x13EC, -1);
                if (self + 0x13C8) {
                    if (self + 0x13CC) __dt__22soControllerModuleImplFv(self + 0x13CC, 0);
                }
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
                    if (self + 0xDE8 && self + 0xDE8) __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 1);
                }
                fn_27_32AB80(self + 0xBDC, -1);
                if (self + 0x9FC) __dt__17soModelModuleImplFv(self + 0xB10, -1);
                if (self + 0x9CC) __dt__20soResourceModuleImplFv(self + 0x9E4, -1);
                if (self + 0x9A4) __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                fn_27_2DA6B8(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}