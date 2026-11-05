#pragma force_active on
extern "C" {
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_2E2534(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
void fn_27_B4780(void*, int);
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
void fn_27_3085C4(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2DA6B8(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_3B4D20(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x1EA0, -1);
        if (self + 0xCC) {
            if (self + 0x18F0) {
                if (self + 0x1DA0 && self + 0x1DA0) {
                    __dt__16acCmdInterpreterFv(self + 0x1DA0, 0);
                }
                if (self + 0x1C74) {
                    if (self + 0x1D50) {
                        __dt__16acCmdInterpreterFv(self + 0x1D50, 0);
                    }
                }
                if (self + 0x1B48) {
                    if (self + 0x1C24) {
                        __dt__16acCmdInterpreterFv(self + 0x1C24, 0);
                    }
                }
                if (self + 0x1A1C) {
                    if (self + 0x1AF8) {
                        __dt__16acCmdInterpreterFv(self + 0x1AF8, 0);
                    }
                }
                if (self + 0x18F0) {
                    if (self + 0x19CC) {
                        __dt__16acCmdInterpreterFv(self + 0x19CC, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x18AC) {
                    fn_27_63EBC(self + 0x18AC, -1);
                }
                if (self + 0x1894) {
                    fn_27_5C674(self + 0x1894, -1);
                }
                fn_27_2DBA8C(self + 0x16F8, -1);
                fn_27_2DB610(self + 0x15E4, -1);
                fn_27_2E2534(self + 0x141C, -1);
                fn_27_1E09C4(self + 0x1378, -1);
                if (self + 0x1344) {
                    fn_27_A1E80(self + 0x1344, -1);
                }
                if (self + 0x1328) {
                    fn_27_B4780(self + 0x132C, -1);
                }
                if (self + 0x1310) {
                    fn_27_5AE44(self + 0x1310, -1);
                }
                if (self + 0x11AC) {
                    fn_27_6A3D8(self + 0x12BC, -1);
                }
                if (self + 0x1144) {
                    fn_27_565F0(self + 0x1150, -1);
                }
                if (self + 0x1138) {
                    fn_27_6880C(self + 0x113C, -1);
                }
                if (self + 0x1110) {
                    __dt__16soStopModuleImplFv(self + 0x1110, -1);
                }
                fn_27_2DAF88(self + 0xF40, -1);
                if (self + 0xEDC) {
                    fn_27_B5324(self + 0xEFC, -1);
                }
                if (self + 0xEA0) {
                    fn_27_3544C(self + 0xEA0, -1);
                }
                if (self + 0xDE8) {
                    __dt__19soPostureModuleImplFv(self + 0xE24, -1);
                    if (self + 0xDE8 && self + 0xDE8) {
                        __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_3085C4(self + 0xBDC, -1);
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