#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_1E2F5C(void*, short);
void* fn_27_379AA0(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void fn_27_B164C(void*, int);
void* fn_27_B21D0(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_379CAC(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_379D80(void*, short);
void* fn_27_1D81C8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_38A5D4(char* self, int flag) {
    if (self) {
        fn_27_1DBB60(self + 0x175C, -1);
        if (self + 0xCC) {
            if (self + 0x1424) {
                if (self + 0x16D4 && self + 0x16D4) {
                    __dt__16acCmdInterpreterFv(self + 0x16D4, 0);
                }
                if (self + 0x160C) {
                    if (self + 0x1684) {
                        __dt__16acCmdInterpreterFv(self + 0x1684, 0);
                    }
                }
                if (self + 0x1558) {
                    if (self + 0x15BC) {
                        __dt__16acCmdInterpreterFv(self + 0x15BC, 0);
                    }
                }
                if (self + 0x14D8) {
                    if (self + 0x1508) {
                        __dt__16acCmdInterpreterFv(self + 0x1508, 0);
                    }
                }
                if (self + 0x1424) {
                    if (self + 0x1488) {
                        __dt__16acCmdInterpreterFv(self + 0x1488, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x1408) fn_27_5C674(self + 0x1408, -1);
                fn_27_2DBA8C(self + 0x126C, -1);
                fn_27_1E2F5C(self + 0x11A4, -1);
                fn_27_379AA0(self + 0x1064, -1);
                fn_27_1E09C4(self + 0xFC0, -1);
                if (self + 0xF8C) fn_27_A1E80(self + 0xF8C, -1);
                if (self + 0xF18) {
                    fn_27_B21D0(self + 0xF68, -1);
                    if (self + 0xF18 && self + 0xF18) {
                        __destroy_arr(self + 0xF24, fn_27_B164C, 0x44, 1);
                    }
                }
                if (self + 0xEE4) fn_27_5B39C(self + 0xEE4, -1);
                if (self + 0xD4C) fn_27_6A3D8(self + 0xE90, -1);
                if (self + 0xCE4) fn_27_565F0(self + 0xCF0, -1);
                if (self + 0xCD8) fn_27_6880C(self + 0xCDC, -1);
                if (self + 0xC68) fn_27_B5324(self + 0xC88, -1);
                if (self + 0xC2C) fn_27_3544C(self + 0xC2C, -1);
                if (self + 0xB84) {
                    fn_27_25740(self + 0xBD4, -1);
                    if (self + 0xB84) {
                        __destroy_arr(self + 0xB90, fn_27_2E888, 0x44, 1);
                    }
                }
                if (self + 0xAD0) {
                    __dt__19soPostureModuleImplFv(self + 0xB0C, -1);
                    if (self + 0xAD0 && self + 0xAD0) {
                        __destroy_arr(self + 0xADC, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_379CAC(self + 0x8B8, -1);
                if (self + 0x670) __dt__17soModelModuleImplFv(self + 0x7EC, -1);
                if (self + 0x640) __dt__20soResourceModuleImplFv(self + 0x658, -1);
                if (self + 0x618) __dt__16soHeapModuleImplFv(self + 0x618, -1);
                __dt__16soModuleAccesserFv(self + 0x538, -1);
                fn_27_379D80(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
