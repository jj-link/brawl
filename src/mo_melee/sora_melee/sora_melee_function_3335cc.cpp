#pragma force_active on
extern "C" {
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_C31CC(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_333ACC(void*, int);
void fn_27_2DB3C8(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
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
void fn_27_2DAB88(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2DA6B8(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_3335CC(char* self, int flag) {
    if (self) {
        if (self + 0x4 && self + 0x4) {
            if (self + 0xD0) {
                if (self + 0x195C) {
                    if (self + 0x1E0C && self + 0x1E0C) {
                        __dt__16acCmdInterpreterFv(self + 0x1E0C, 0);
                    }
                    if (self + 0x1CE0) {
                        if (self + 0x1DBC) {
                            __dt__16acCmdInterpreterFv(self + 0x1DBC, 0);
                        }
                    }
                    if (self + 0x1BB4) {
                        if (self + 0x1C90) {
                            __dt__16acCmdInterpreterFv(self + 0x1C90, 0);
                        }
                    }
                    if (self + 0x1A88) {
                        if (self + 0x1B64) {
                            __dt__16acCmdInterpreterFv(self + 0x1B64, 0);
                        }
                    }
                    if (self + 0x195C) {
                        if (self + 0x1A38) {
                            __dt__16acCmdInterpreterFv(self + 0x1A38, 0);
                        }
                    }
                }
                if (self + 0xD0) {
                    if (self + 0x1940) {
                        fn_27_C31CC(self + 0x1940, -1);
                    }
                    if (self + 0x1900) {
                        fn_27_63EBC(self + 0x1900, -1);
                    }
                    if (self + 0x18E8) {
                        fn_27_5C674(self + 0x18E8, -1);
                    }
                    fn_27_2DBA8C(self + 0x174C, -1);
                    fn_27_333ACC(self + 0x15C4, -1);
                    fn_27_2DB3C8(self + 0x1404, -1);
                    fn_27_1E09C4(self + 0x1360, -1);
                    if (self + 0x132C) {
                        fn_27_A1E80(self + 0x132C, -1);
                    }
                    if (self + 0x1314) {
                        fn_27_5AE44(self + 0x1314, -1);
                    }
                    if (self + 0x11B0) {
                        fn_27_6A3D8(self + 0x12C0, -1);
                    }
                    if (self + 0x1148) {
                        fn_27_565F0(self + 0x1154, -1);
                    }
                    if (self + 0x113C) {
                        fn_27_6880C(self + 0x1140, -1);
                    }
                    if (self + 0x1114) {
                        __dt__16soStopModuleImplFv(self + 0x1114, -1);
                    }
                    fn_27_2DAF88(self + 0xF44, -1);
                    if (self + 0xEE0) {
                        fn_27_B5324(self + 0xF00, -1);
                    }
                    if (self + 0xEA4) {
                        fn_27_3544C(self + 0xEA4, -1);
                    }
                    if (self + 0xDEC) {
                        __dt__19soPostureModuleImplFv(self + 0xE28, -1);
                        if (self + 0xDEC && self + 0xDEC) {
                            __destroy_arr(self + 0xDF8, fn_27_25290, 0x30, 1);
                        }
                    }
                    fn_27_2DAB88(self + 0xBE0, -1);
                    if (self + 0xA00) {
                        __dt__17soModelModuleImplFv(self + 0xB14, -1);
                    }
                    if (self + 0x9D0) {
                        __dt__20soResourceModuleImplFv(self + 0x9E8, -1);
                    }
                    if (self + 0x9A8) {
                        __dt__16soHeapModuleImplFv(self + 0x9A8, -1);
                    }
                    __dt__16soModuleAccesserFv(self + 0x8C8, -1);
                    fn_27_2DA6B8(self + 0xD0, -1);
                }
            }
            fn_27_1D81C8(self + 0x4, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
