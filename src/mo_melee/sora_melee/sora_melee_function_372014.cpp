#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_36A0A4(void*, short);
void* fn_27_1E2F5C(void*, short);
void* fn_27_36E8F8(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
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
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_372014(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x15F8, -1);
            if (self + 0xCC) {
                if (self + 0x12C8) {
                    if (self + 0x1584 && self + 0x1584)
                        __dt__16acCmdInterpreterFv(self + 0x1584, 0);
                    if (self + 0x14D0) {
                        if (self + 0x1534)
                            __dt__16acCmdInterpreterFv(self + 0x1534, 0);
                    }
                    if (self + 0x141C) {
                        if (self + 0x1480)
                            __dt__16acCmdInterpreterFv(self + 0x1480, 0);
                    }
                    if (self + 0x1368) {
                        if (self + 0x13CC)
                            __dt__16acCmdInterpreterFv(self + 0x13CC, 0);
                    }
                    if (self + 0x12C8) {
                        if (self + 0x1318)
                            __dt__16acCmdInterpreterFv(self + 0x1318, 0);
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x12AC) fn_27_C31CC(self + 0x12AC, -1);
                    if (self + 0x126C) fn_27_63EBC(self + 0x126C, -1);
                    if (self + 0x1254) fn_27_5C674(self + 0x1254, -1);
                    fn_27_36A0A4(self + 0x10FC, -1);
                    fn_27_1E2F5C(self + 0x1024, -1);
                    fn_27_36E8F8(self + 0xEF4, -1);
                    fn_27_1E09C4(self + 0xE50, -1);
                    if (self + 0xE1C) fn_27_A1E80(self + 0xE1C, -1);
                    if (self + 0xE04) fn_27_5AE44(self + 0xE04, -1);
                    if (self + 0xCA0) fn_27_6A3D8(self + 0xDB0, -1);
                    if (self + 0xC90) fn_27_6880C(self + 0xC94, -1);
                    if (self + 0xC68) __dt__16soStopModuleImplFv(self + 0xC68, -1);
                    fn_27_2DAF88(self + 0xA98, -1);
                    if (self + 0xA34) fn_27_B5324(self + 0xA54, -1);
                    if (self + 0x9F8) fn_27_3544C(self + 0x9F8, -1);
                    if (self + 0x950) {
                        fn_27_25740(self + 0x9A0, -1);
                        if (self + 0x950) __destroy_arr(self + 0x95C, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0x89C) {
                        __dt__19soPostureModuleImplFv(self + 0x8D8, -1);
                        if (self + 0x89C && self + 0x89C) __destroy_arr(self + 0x8A8, fn_27_25290, 0x30, 1);
                    }
                    if (self + 0x710) fn_27_13C90(self + 0x72C, -1);
                    if (self + 0x600) __dt__17soModelModuleImplFv(self + 0x644, -1);
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