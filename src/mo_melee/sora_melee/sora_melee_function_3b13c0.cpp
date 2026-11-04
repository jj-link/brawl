#pragma force_active on
extern "C" {
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_2DB3C8(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
void __dt__22soControllerModuleImplFv(void*, short);
void fn_27_5AE44(void*, int);
void fn_27_6A3D8(void*, int);
void fn_27_565F0(void*, int);
void fn_27_6880C(void*, int);
void __dt__16soStopModuleImplFv(void*, short);
void fn_27_2DAF88(void*, int);
void fn_27_B5324(void*, int);
void fn_27_3544C(void*, int);
void __dt__19soPostureModuleImplFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_25290(void*, int);
void fn_27_3B164C(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2DA6B8(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_3B13C0(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x1F04, -1);
        if (self + 0xCC) {
            if (self + 0x1954) {
                if (self + 0x1E04 && self + 0x1E04) {
                    __dt__16acCmdInterpreterFv(self + 0x1E04, 0);
                }
                if (self + 0x1CD8) {
                    if (self + 0x1DB4) {
                        __dt__16acCmdInterpreterFv(self + 0x1DB4, 0);
                    }
                }
                if (self + 0x1BAC) {
                    if (self + 0x1C88) {
                        __dt__16acCmdInterpreterFv(self + 0x1C88, 0);
                    }
                }
                if (self + 0x1A80) {
                    if (self + 0x1B5C) {
                        __dt__16acCmdInterpreterFv(self + 0x1B5C, 0);
                    }
                }
                if (self + 0x1954) {
                    if (self + 0x1A30) {
                        __dt__16acCmdInterpreterFv(self + 0x1A30, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x1910) {
                    fn_27_63EBC(self + 0x1910, -1);
                }
                if (self + 0x18F8) {
                    fn_27_5C674(self + 0x18F8, -1);
                }
                fn_27_2DBA8C(self + 0x175C, -1);
                fn_27_2DB610(self + 0x1648, -1);
                fn_27_2DB3C8(self + 0x1488, -1);
                fn_27_1E09C4(self + 0x13E4, -1);
                if (self + 0x13B0) {
                    fn_27_A1E80(self + 0x13B0, -1);
                }
                if (self + 0x138C) {
                    if (self + 0x1390) {
                        __dt__22soControllerModuleImplFv(self + 0x1390, 0);
                    }
                }
                if (self + 0x1378) {
                    fn_27_5AE44(self + 0x1378, -1);
                }
                if (self + 0x1214) {
                    fn_27_6A3D8(self + 0x1324, -1);
                }
                if (self + 0x11AC) {
                    fn_27_565F0(self + 0x11B8, -1);
                }
                if (self + 0x11A0) {
                    fn_27_6880C(self + 0x11A4, -1);
                }
                if (self + 0x1178) {
                    __dt__16soStopModuleImplFv(self + 0x1178, -1);
                }
                fn_27_2DAF88(self + 0xFA8, -1);
                if (self + 0xF44) {
                    fn_27_B5324(self + 0xF64, -1);
                }
                if (self + 0xF08) {
                    fn_27_3544C(self + 0xF08, -1);
                }
                if (self + 0xE50) {
                    __dt__19soPostureModuleImplFv(self + 0xE8C, -1);
                    if (self + 0xE50 && self + 0xE50) {
                        __destroy_arr(self + 0xE5C, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_3B164C(self + 0xBDC, -1);
                if (self + 0x9FC) {
                    __dt__17soModelModuleImplFv(self + 0xB10, -1);
                }
                if (self + 0x9CC) {
                    __dt__20soResourceModuleImplFv(self + 0x9E4, -1);
                }
                if (self + 0x9A4) {
                    __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                }
                __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                fn_27_2DA6B8(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
