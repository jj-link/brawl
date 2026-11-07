#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_33D848(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_314010(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_33D9D4(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_33DA84(void*, short);
void* fn_27_1D81C8(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_27_33D590(char* self, int flag) {
    if (self) {
        fn_27_1DBB60(self + 0x1B18, -1);
        if (self + 0xCC) {
            if (self + 0x17C0) {
                if (self + 0x1A90 && self + 0x1A90) {
                    __dt__16acCmdInterpreterFv(self + 0x1A90, 0);
                }
                if (self + 0x19DC) {
                    if (self + 0x1A40) __dt__16acCmdInterpreterFv(self + 0x1A40, 0);
                }
                if (self + 0x1928) {
                    if (self + 0x198C) __dt__16acCmdInterpreterFv(self + 0x198C, 0);
                }
                if (self + 0x1874) {
                    if (self + 0x18D8) __dt__16acCmdInterpreterFv(self + 0x18D8, 0);
                }
                if (self + 0x17C0) {
                    if (self + 0x1824) __dt__16acCmdInterpreterFv(self + 0x1824, 0);
                }
            }
            if (self + 0xCC) {
                if (self + 0x17A4) fn_27_C31CC(self + 0x17A4, -1);
                if (self + 0x1764) fn_27_63EBC(self + 0x1764, -1);
                if (self + 0x174C) fn_27_5C674(self + 0x174C, -1);
                fn_27_2DBA8C(self + 0x15B0, -1);
                fn_27_2DB610(self + 0x149C, -1);
                fn_27_33D848(self + 0x1310, -1);
                fn_27_1E09C4(self + 0x126C, -1);
                if (self + 0x1238) fn_27_A1E80(self + 0x1238, -1);
                if (self + 0x1220) fn_27_5AE44(self + 0x1220, -1);
                if (self + 0x10BC) fn_27_6A3D8(self + 0x11CC, -1);
                if (self + 0x1054) fn_27_565F0(self + 0x1060, -1);
                if (self + 0x1048) fn_27_6880C(self + 0x104C, -1);
                if (self + 0x1020) __dt__16soStopModuleImplFv(self + 0x1020, -1);
                fn_27_314010(self + 0xCA0, -1);
                if (self + 0xC3C) fn_27_B5324(self + 0xC5C, -1);
                if (self + 0xC00) fn_27_3544C(self + 0xC00, -1);
                if (self + 0xB58) {
                    fn_27_25740(self + 0xBA8, -1);
                    if (self + 0xB58) __destroy_arr(self + 0xB64, fn_27_2E888, 0x44, 1);
                }
                if (self + 0xAA4) {
                    __dt__19soPostureModuleImplFv(self + 0xAE0, -1);
                    if (self + 0xAA4 && self + 0xAA4) __destroy_arr(self + 0xAB0, fn_27_25290, 0x30, 1);
                }
                fn_27_33D9D4(self + 0x898, -1);
                if (self + 0x6B8) __dt__17soModelModuleImplFv(self + 0x7CC, -1);
                if (self + 0x688) __dt__20soResourceModuleImplFv(self + 0x6A0, -1);
                if (self + 0x660) __dt__16soHeapModuleImplFv(self + 0x660, -1);
                __dt__16soModuleAccesserFv(self + 0x580, -1);
                fn_27_33DA84(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
