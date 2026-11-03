#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_304890(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_6880C(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_13C90(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_27_2ECF44(void*, short);
void* fn_27_1D81C8(void*, short);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}
extern "C" void* fn_27_3045E4(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x1724, -1);
        if (self + 0xCC) {
            if (self + 0x1408) {
                if (self + 0x169C && self + 0x169C)
                    __dt__16acCmdInterpreterFv(self + 0x169C, 0);
                if (self + 0x15FC) {
                    if (self + 0x164C) __dt__16acCmdInterpreterFv(self + 0x164C, 0);
                }
                if (self + 0x155C) {
                    if (self + 0x15AC) __dt__16acCmdInterpreterFv(self + 0x15AC, 0);
                }
                if (self + 0x14BC) {
                    if (self + 0x150C) __dt__16acCmdInterpreterFv(self + 0x150C, 0);
                }
                if (self + 0x1408) {
                    if (self + 0x146C) __dt__16acCmdInterpreterFv(self + 0x146C, 0);
                }
            }
            if (self + 0xCC) {
                if (self + 0x13EC) fn_27_C31CC(self + 0x13EC, -1);
                if (self + 0x13AC) fn_27_63EBC(self + 0x13AC, -1);
                if (self + 0x1394) fn_27_5C674(self + 0x1394, -1);
                fn_27_2DBA8C(self + 0x11F8, -1);
                fn_27_2DB610(self + 0x10E4, -1);
                fn_27_304890(self + 0xF70, -1);
                fn_27_1E09C4(self + 0xECC, -1);
                if (self + 0xE98) fn_27_A1E80(self + 0xE98, -1);
                if (self + 0xE80) fn_27_5AE44(self + 0xE80, -1);
                if (self + 0xD1C) fn_27_6A3D8(self + 0xE2C, -1);
                if (self + 0xD0C) fn_27_6880C(self + 0xD10, -1);
                if (self + 0xCE4) __dt__16soStopModuleImplFv(self + 0xCE4, -1);
                fn_27_2DAF88(self + 0xB14, -1);
                if (self + 0xAB0) fn_27_B5324(self + 0xAD0, -1);
                if (self + 0xA74) fn_27_3544C(self + 0xA74, -1);
                if (self + 0x9CC) {
                    fn_27_25740(self + 0xA1C, -1);
                    if (self + 0x9CC) __destroy_arr(self + 0x9D8, fn_27_2E888, 0x44, 1);
                }
                if (self + 0x918) {
                    __dt__19soPostureModuleImplFv(self + 0x954, -1);
                    if (self + 0x918 && self + 0x918)
                        __destroy_arr(self + 0x924, fn_27_25290, 0x30, 1);
                }
                if (self + 0x78C) fn_27_13C90(self + 0x7A8, -1);
                if (self + 0x67C) __dt__17soModelModuleImplFv(self + 0x6C0, -1);
                if (self + 0x64C) __dt__20soResourceModuleImplFv(self + 0x664, -1);
                if (self + 0x624) __dt__16soHeapModuleImplFv(self + 0x624, -1);
                __dt__16soModuleAccesserFv(self + 0x544, -1);
                fn_27_2ECF44(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) __dl__FPv(self);
    }
    return self;
}