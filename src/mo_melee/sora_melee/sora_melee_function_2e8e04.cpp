#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, int);
void* fn_27_2E76C0(void*, int);
void* fn_27_2E7480(void*, int);
void* fn_27_1E09C4(void*, int);
void* fn_27_A1E80(void*, int);
void* fn_27_5AE44(void*, int);
void* fn_27_6A3D8(void*, int);
void* fn_27_565F0(void*, int);
void* fn_27_6880C(void*, int);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_2E70E0(void*, int);
void* fn_27_2DAF88(void*, int);
void* fn_27_B5324(void*, int);
void* fn_27_3544C(void*, int);
void* fn_27_25740(void*, int);
void* fn_27_13C90(void*, int);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_2E67B0(void*, int);
void* fn_27_1D81C8(void*, int);
void* __dt__19soPostureModuleImplFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void __dl__FPv(void*);
}
extern "C" void* fn_27_2E8E04(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x19F8, -1);
        if (self + 0xCC) {
            if (self + 0x16A0) {
                if (self + 0x1970 && self + 0x1970)
                    __dt__16acCmdInterpreterFv(self + 0x1970, 0);
                if (self + 0x18BC) {
                    if (self + 0x1920) __dt__16acCmdInterpreterFv(self + 0x1920, 0);
                }
                if (self + 0x1808) {
                    if (self + 0x186C) __dt__16acCmdInterpreterFv(self + 0x186C, 0);
                }
                if (self + 0x1754) {
                    if (self + 0x17B8) __dt__16acCmdInterpreterFv(self + 0x17B8, 0);
                }
                if (self + 0x16A0) {
                    if (self + 0x1704) __dt__16acCmdInterpreterFv(self + 0x1704, 0);
                }
            }
            if (self + 0xCC) {
                if (self + 0x1684) fn_27_C31CC(self + 0x1684, -1);
                if (self + 0x1644) fn_27_63EBC(self + 0x1644, -1);
                if (self + 0x162C) fn_27_5C674(self + 0x162C, -1);
                fn_27_2DBA8C(self + 0x1490, -1);
                fn_27_2E76C0(self + 0x13B8, -1);
                fn_27_2E7480(self + 0x1234, -1);
                fn_27_1E09C4(self + 0x1190, -1);
                if (self + 0x115C) fn_27_A1E80(self + 0x115C, -1);
                if (self + 0x1144) fn_27_5AE44(self + 0x1144, -1);
                if (self + 0xFE0) fn_27_6A3D8(self + 0x10F0, -1);
                if (self + 0xF78) fn_27_565F0(self + 0xF84, -1);
                if (self + 0xF6C) fn_27_6880C(self + 0xF70, -1);
                if (self + 0xF44) __dt__16soStopModuleImplFv(self + 0xF44, -1);
                fn_27_2E70E0(self + 0xD48, -1);
                fn_27_2DAF88(self + 0xB7C, -1);
                if (self + 0xB18) fn_27_B5324(self + 0xB38, -1);
                if (self + 0xADC) fn_27_3544C(self + 0xADC, -1);
                if (self + 0xA34) {
                    fn_27_25740(self + 0xA84, -1);
                    if (self + 0xA34) __destroy_arr(self + 0xA40, fn_27_2E888, 0x44, 1);
                }
                if (self + 0x980) {
                    __dt__19soPostureModuleImplFv(self + 0x9BC, -1);
                    if (self + 0x980 && self + 0x980)
                        __destroy_arr(self + 0x98C, fn_27_25290, 0x30, 1);
                }
                if (self + 0x7F4) fn_27_13C90(self + 0x810, -1);
                if (self + 0x6E4) __dt__17soModelModuleImplFv(self + 0x728, -1);
                if (self + 0x6B4) __dt__20soResourceModuleImplFv(self + 0x6CC, -1);
                if (self + 0x68C) __dt__16soHeapModuleImplFv(self + 0x68C, -1);
                __dt__16soModuleAccesserFv(self + 0x5AC, -1);
                fn_27_2E67B0(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) __dl__FPv(self);
    }
    return self;
}