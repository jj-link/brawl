#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__16acCmdInterpreterFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_36A0A4(void*, short);
void* fn_27_37A59C(void*, short);
void* fn_27_37A6D4(void*, short);
void* fn_27_37A770(void*, short);
void* fn_27_37A844(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_B21D0(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_B64B8(void*, short);
void* fn_27_BED74(void*, short);
void fn_27_B164C(void*, int);
void fn_27_25290(void*, int);
void fn_27_2E888(void*, int);
}

extern "C" void* fn_27_3915A8(char* self, int flags) {
    if (self) {
        if (self + 0xCC) {
            if (self + 0x1C90) {
                if (self + 0x1F74 && self + 0x1F74) {
                    __dt__16acCmdInterpreterFv(self + 0x1F74, 0);
                }
                if (self + 0x1EC0) {
                    if (self + 0x1F24) {
                        __dt__16acCmdInterpreterFv(self + 0x1F24, 0);
                    }
                }
                if (self + 0x1E0C) {
                    if (self + 0x1E70) {
                        __dt__16acCmdInterpreterFv(self + 0x1E70, 0);
                    }
                }
                if (self + 0x1D44) {
                    if (self + 0x1DBC) {
                        __dt__16acCmdInterpreterFv(self + 0x1DBC, 0);
                    }
                }
                if (self + 0x1C90) {
                    if (self + 0x1CF4) {
                        __dt__16acCmdInterpreterFv(self + 0x1CF4, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x1C74) {
                    fn_27_5C674(self + 0x1C74, -1);
                }
                if (self + 0x1B1C) {
                    fn_27_BED74(self + 0x1B1C, -1);
                }
                if (self + 0x1AD0) {
                    fn_27_B64B8(self + 0x1AD0, -1);
                }
                fn_27_36A0A4(self + 0x197C, -1);
                fn_27_37A59C(self + 0x17E0, -1);
                fn_27_1E09C4(self + 0x173C, -1);
                if (self + 0x1708) {
                    fn_27_A1E80(self + 0x1708, -1);
                }
                if (self + 0x1694) {
                    fn_27_B21D0(self + 0x16E4, -1);
                    if (self + 0x1694 && self + 0x1694) {
                        __destroy_arr(self + 0x16A0, fn_27_B164C, 0x44, 1);
                    }
                }
                if (self + 0x1660) {
                    fn_27_5B39C(self + 0x1660, -1);
                }
                if (self + 0x14C8) {
                    fn_27_6A3D8(self + 0x160C, -1);
                }
                if (self + 0x1460) {
                    fn_27_565F0(self + 0x146C, -1);
                }
                if (self + 0x1454) {
                    fn_27_6880C(self + 0x1458, -1);
                }
                fn_27_37A6D4(self + 0xC54, -1);
                if (self + 0xBF0) {
                    fn_27_B5324(self + 0xC10, -1);
                }
                if (self + 0xBB4) {
                    fn_27_3544C(self + 0xBB4, -1);
                }
                if (self + 0xB0C) {
                    fn_27_25740(self + 0xB5C, -1);
                    if (self + 0xB0C) {
                        __destroy_arr(self + 0xB18, fn_27_2E888, 0x44, 1);
                    }
                }
                if (self + 0xA58) {
                    __dt__19soPostureModuleImplFv(self + 0xA94, -1);
                    if (self + 0xA58 && self + 0xA58) {
                        __destroy_arr(self + 0xA64, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_37A770(self + 0x840, -1);
                if (self + 0x694) {
                    __dt__17soModelModuleImplFv(self + 0x774, -1);
                }
                if (self + 0x664) {
                    __dt__20soResourceModuleImplFv(self + 0x67C, -1);
                }
                if (self + 0x63C) {
                    __dt__16soHeapModuleImplFv(self + 0x63C, -1);
                }
                __dt__16soModuleAccesserFv(self + 0x55C, -1);
                fn_27_37A844(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
