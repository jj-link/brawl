#pragma force_active on

extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_36A0A4(void*, short);
void* fn_27_1E2F5C(void*, short);
void* fn_27_3738B4(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_36EA84(void*, short);
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

extern "C" void* fn_27_376300(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x15C8, -1);
            if (self + 0xCC) {
                if (self + 0x12B4) {
                    if (self + 0x1570 && self + 0x1570) {
                        __dt__16acCmdInterpreterFv(self + 0x1570, 0);
                    }
                    if (self + 0x14BC) {
                        if (self + 0x1520) {
                            __dt__16acCmdInterpreterFv(self + 0x1520, 0);
                        }
                    }
                    if (self + 0x1408) {
                        if (self + 0x146C) {
                            __dt__16acCmdInterpreterFv(self + 0x146C, 0);
                        }
                    }
                    if (self + 0x1354) {
                        if (self + 0x13B8) {
                            __dt__16acCmdInterpreterFv(self + 0x13B8, 0);
                        }
                    }
                    if (self + 0x12B4) {
                        if (self + 0x1304) {
                            __dt__16acCmdInterpreterFv(self + 0x1304, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x1298) fn_27_C31CC(self + 0x1298, -1);
                    if (self + 0x1258) fn_27_63EBC(self + 0x1258, -1);
                    if (self + 0x1240) fn_27_5C674(self + 0x1240, -1);
                    fn_27_36A0A4(self + 0x10E8, -1);
                    fn_27_1E2F5C(self + 0x1014, -1);
                    fn_27_3738B4(self + 0xED4, -1);
                    fn_27_1E09C4(self + 0xE30, -1);
                    if (self + 0xDFC) fn_27_A1E80(self + 0xDFC, -1);
                    if (self + 0xC94) fn_27_6A3D8(self + 0xDA4, -1);
                    if (self + 0xC84) fn_27_6880C(self + 0xC88, -1);
                    if (self + 0xC5C) __dt__16soStopModuleImplFv(self + 0xC5C, -1);
                    fn_27_2DAF88(self + 0xA8C, -1);
                    if (self + 0xA28) fn_27_B5324(self + 0xA48, -1);
                    if (self + 0x97C) {
                        fn_27_25740(self + 0x9CC, -1);
                        if (self + 0x97C) {
                            __destroy_arr(self + 0x988, fn_27_2E888, 0x44, 1);
                        }
                    }
                    if (self + 0x8C8) {
                        __dt__19soPostureModuleImplFv(self + 0x904, -1);
                        if (self + 0x8C8 && self + 0x8C8) {
                            __destroy_arr(self + 0x8D4, fn_27_25290, 0x30, 1);
                        }
                    }
                    if (self + 0x73C) fn_27_13C90(self + 0x758, -1);
                    if (self + 0x62C) __dt__17soModelModuleImplFv(self + 0x670, -1);
                    if (self + 0x5FC) __dt__20soResourceModuleImplFv(self + 0x614, -1);
                    if (self + 0x5D4) __dt__16soHeapModuleImplFv(self + 0x5D4, -1);
                    __dt__16soModuleAccesserFv(self + 0x4F4, -1);
                    fn_27_36EA84(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
