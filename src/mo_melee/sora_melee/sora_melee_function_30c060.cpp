#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2E2534(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5B39C(void*, short);
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
void* fn_27_30C318(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_2DA6B8(void*, short);
void* fn_27_1D81C8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_30C060(char* self, int flag) {
    if (self) {
        fn_27_1DBB60(self + 0x1F98, -1);
        if (self + 0xCC) {
            if (self + 0x19E8) {
                if (self + 0x1E98 && self + 0x1E98) {
                    __dt__16acCmdInterpreterFv(self + 0x1E98, 0);
                }
                if (self + 0x1D6C) {
                    if (self + 0x1E48) {
                        __dt__16acCmdInterpreterFv(self + 0x1E48, 0);
                    }
                }
                if (self + 0x1C40) {
                    if (self + 0x1D1C) {
                        __dt__16acCmdInterpreterFv(self + 0x1D1C, 0);
                    }
                }
                if (self + 0x1B14) {
                    if (self + 0x1BF0) {
                        __dt__16acCmdInterpreterFv(self + 0x1BF0, 0);
                    }
                }
                if (self + 0x19E8) {
                    if (self + 0x1AC4) {
                        __dt__16acCmdInterpreterFv(self + 0x1AC4, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x19CC) fn_27_C31CC(self + 0x19CC, -1);
                if (self + 0x198C) fn_27_63EBC(self + 0x198C, -1);
                if (self + 0x1974) fn_27_5C674(self + 0x1974, -1);
                fn_27_2DBA8C(self + 0x17D8, -1);
                fn_27_2DB610(self + 0x16C4, -1);
                fn_27_2E2534(self + 0x14FC, -1);
                fn_27_1E09C4(self + 0x1458, -1);
                if (self + 0x1424) fn_27_A1E80(self + 0x1424, -1);
                if (self + 0x13F0) fn_27_5B39C(self + 0x13F0, -1);
                if (self + 0x128C) fn_27_6A3D8(self + 0x139C, -1);
                if (self + 0x1224) fn_27_565F0(self + 0x1230, -1);
                if (self + 0x1218) fn_27_6880C(self + 0x121C, -1);
                if (self + 0x11F0) __dt__16soStopModuleImplFv(self + 0x11F0, -1);
                fn_27_2DAF88(self + 0x1020, -1);
                if (self + 0xFBC) fn_27_B5324(self + 0xFDC, -1);
                if (self + 0xF80) fn_27_3544C(self + 0xF80, -1);
                if (self + 0xED8) {
                    fn_27_25740(self + 0xF28, -1);
                    if (self + 0xED8) __destroy_arr(self + 0xEE4, fn_27_2E888, 0x44, 1);
                }
                if (self + 0xE24) {
                    __dt__19soPostureModuleImplFv(self + 0xE60, -1);
                    if (self + 0xE24 && self + 0xE24) __destroy_arr(self + 0xE30, fn_27_25290, 0x30, 1);
                }
                fn_27_30C318(self + 0xBDC, -1);
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