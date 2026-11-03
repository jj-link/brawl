#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2DB3C8(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_327AE8(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_25740(void*, short);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_2DAB88(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_2DA6B8(void*, short);
void* fn_27_1D81C8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_327B84(char* self, int flag) {
    if (self) {
        fn_27_1DBB60(self + 0x1F3C, -1);
        if (self + 0xCC) {
            if (self + 0x198C) {
                if (self + 0x1E3C && self + 0x1E3C) {
                    __dt__16acCmdInterpreterFv(self + 0x1E3C, 0);
                }
                if (self + 0x1D10) {
                    if (self + 0x1DEC) {
                        __dt__16acCmdInterpreterFv(self + 0x1DEC, 0);
                    }
                }
                if (self + 0x1BE4) {
                    if (self + 0x1CC0) {
                        __dt__16acCmdInterpreterFv(self + 0x1CC0, 0);
                    }
                }
                if (self + 0x1AB8) {
                    if (self + 0x1B94) {
                        __dt__16acCmdInterpreterFv(self + 0x1B94, 0);
                    }
                }
                if (self + 0x198C) {
                    if (self + 0x1A68) {
                        __dt__16acCmdInterpreterFv(self + 0x1A68, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x1970) fn_27_C31CC(self + 0x1970, -1);
                if (self + 0x1930) fn_27_63EBC(self + 0x1930, -1);
                if (self + 0x1918) fn_27_5C674(self + 0x1918, -1);
                fn_27_2DBA8C(self + 0x177C, -1);
                fn_27_2DB610(self + 0x1680, -1);
                fn_27_2DB3C8(self + 0x14C0, -1);
                fn_27_1E09C4(self + 0x141C, -1);
                if (self + 0x13E8) fn_27_A1E80(self + 0x13E8, -1);
                if (self + 0x1280) fn_27_6A3D8(self + 0x1390, -1);
                if (self + 0x1218) fn_27_565F0(self + 0x1224, -1);
                if (self + 0x120C) fn_27_6880C(self + 0x1210, -1);
                fn_27_327AE8(self + 0xFAC, -1);
                if (self + 0xF48) fn_27_B5324(self + 0xF68, -1);
                if (self + 0xE9C) {
                    fn_27_25740(self + 0xEEC, -1);
                    if (self + 0xE9C) __destroy_arr(self + 0xEA8, fn_27_2E888, 0x44, 1);
                }
                if (self + 0xDE8) {
                    __dt__19soPostureModuleImplFv(self + 0xE24, -1);
                    if (self + 0xDE8 && self + 0xDE8) __destroy_arr(self + 0xDF4, fn_27_25290, 0x30, 1);
                }
                fn_27_2DAB88(self + 0xBDC, -1);
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