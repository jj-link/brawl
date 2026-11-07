#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2DB3C8(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_2DAB88(void*, short);
void* fn_27_2DA6B8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
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

extern "C" void* fn_27_3135A8(char* self, int flag) {
    if (self) {
        if (self + 0x4 && self + 0x4) {
            fn_27_1DBB60(self + 0x1E80, -1);
            if (self + 0xD0) {
                if (self + 0x18D0) {
                    if (self + 0x1D80 && self + 0x1D80) {
                        __dt__16acCmdInterpreterFv(self + 0x1D80, 0);
                    }
                    if (self + 0x1C54) {
                        if (self + 0x1D30) {
                            __dt__16acCmdInterpreterFv(self + 0x1D30, 0);
                        }
                    }
                    if (self + 0x1B28) {
                        if (self + 0x1C04) {
                            __dt__16acCmdInterpreterFv(self + 0x1C04, 0);
                        }
                    }
                    if (self + 0x19FC) {
                        if (self + 0x1AD8) {
                            __dt__16acCmdInterpreterFv(self + 0x1AD8, 0);
                        }
                    }
                    if (self + 0x18D0) {
                        if (self + 0x19AC) {
                            __dt__16acCmdInterpreterFv(self + 0x19AC, 0);
                        }
                    }
                }
                if (self + 0xD0) {
                    if (self + 0x188C) {
                        fn_27_63EBC(self + 0x188C, -1);
                    }
                    if (self + 0x1874) {
                        fn_27_5C674(self + 0x1874, -1);
                    }
                    fn_27_2DBA8C(self + 0x16D8, -1);
                    fn_27_2DB610(self + 0x15C4, -1);
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
