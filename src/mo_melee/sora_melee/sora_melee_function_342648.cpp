#pragma force_active on

extern "C" {
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_3428B0(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
void fn_27_5B39C(void*, int);
void fn_27_6A3D8(void*, int);
void fn_27_565F0(void*, int);
void fn_27_6880C(void*, int);
void __dt__16soStopModuleImplFv(void*, short);
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
void fn_27_342A3C(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_342648(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x1748, -1);
        if (self + 0xCC) {
            if (self + 0x13F0) {
                if (self + 0x16C0 && self + 0x16C0) {
                    __dt__16acCmdInterpreterFv(self + 0x16C0, 0);
                }
                if (self + 0x160C) {
                    if (self + 0x1670) {
                        __dt__16acCmdInterpreterFv(self + 0x1670, 0);
                    }
                }
                if (self + 0x1558) {
                    if (self + 0x15BC) {
                        __dt__16acCmdInterpreterFv(self + 0x15BC, 0);
                    }
                }
                if (self + 0x14A4) {
                    if (self + 0x1508) {
                        __dt__16acCmdInterpreterFv(self + 0x1508, 0);
                    }
                }
                if (self + 0x13F0) {
                    if (self + 0x1454) {
                        __dt__16acCmdInterpreterFv(self + 0x1454, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x13AC) {
                    fn_27_63EBC(self + 0x13AC, -1);
                }
                if (self + 0x1394) {
                    fn_27_5C674(self + 0x1394, -1);
                }
                fn_27_2DBA8C(self + 0x11F8, -1);
                fn_27_2DB610(self + 0x10E4, -1);
                fn_27_3428B0(self + 0xF58, -1);
                fn_27_1E09C4(self + 0xEB4, -1);
                if (self + 0xE80) {
                    fn_27_A1E80(self + 0xE80, -1);
                }
                if (self + 0xE4C) {
                    fn_27_5B39C(self + 0xE4C, -1);
                }
                if (self + 0xCE8) {
                    fn_27_6A3D8(self + 0xDF8, -1);
                }
                if (self + 0xC80) {
                    fn_27_565F0(self + 0xC8C, -1);
                }
                if (self + 0xC74) {
                    fn_27_6880C(self + 0xC78, -1);
                }
                if (self + 0xC4C) {
                    __dt__16soStopModuleImplFv(self + 0xC4C, -1);
                }
                if (self + 0xBDC) {
                    fn_27_B5324(self + 0xBFC, -1);
                }
                if (self + 0xBA0) {
                    fn_27_3544C(self + 0xBA0, -1);
                }
                if (self + 0xAE8) {
                    __dt__19soPostureModuleImplFv(self + 0xB24, -1);
                    if (self + 0xAE8 && self + 0xAE8) {
                        __destroy_arr(self + 0xAF4, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_2DAB88(self + 0x8DC, -1);
                if (self + 0x6FC) {
                    __dt__17soModelModuleImplFv(self + 0x810, -1);
                }
                if (self + 0x6CC) {
                    __dt__20soResourceModuleImplFv(self + 0x6E4, -1);
                }
                if (self + 0x6A4) {
                    __dt__16soHeapModuleImplFv(self + 0x6A4, -1);
                }
                __dt__16soModuleAccesserFv(self + 0x5C4, -1);
                fn_27_342A3C(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
