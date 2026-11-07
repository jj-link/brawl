#pragma force_active on
extern "C" {
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_10424(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_2F80A0(void*, int);
void fn_27_1E09C4(void*, int);
void fn_27_A1E80(void*, int);
void fn_27_5AE44(void*, int);
void fn_27_6A3D8(void*, int);
void fn_27_565F0(void*, int);
void fn_27_6880C(void*, int);
void __dt__16soStopModuleImplFv(void*, short);
void fn_27_B5324(void*, int);
void fn_27_3544C(void*, int);
void __dt__19soPostureModuleImplFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_27_25290(void*, int);
void fn_27_2F822C(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2ECF44(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_2F7E24(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x16CC, -1);
        if (self + 0xCC) {
            if (self + 0x1374) {
                if (self + 0x1644 && self + 0x1644) {
                    __dt__16acCmdInterpreterFv(self + 0x1644, 0);
                }
                if (self + 0x1590) {
                    if (self + 0x15F4) {
                        __dt__16acCmdInterpreterFv(self + 0x15F4, 0);
                    }
                }
                if (self + 0x14DC) {
                    if (self + 0x1540) {
                        __dt__16acCmdInterpreterFv(self + 0x1540, 0);
                    }
                }
                if (self + 0x1428) {
                    if (self + 0x148C) {
                        __dt__16acCmdInterpreterFv(self + 0x148C, 0);
                    }
                }
                if (self + 0x1374) {
                    if (self + 0x13D8) {
                        __dt__16acCmdInterpreterFv(self + 0x13D8, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x1330) {
                    fn_27_63EBC(self + 0x1330, -1);
                }
                if (self + 0x1318) {
                    fn_27_5C674(self + 0x1318, -1);
                }
                if (self + 0x12C4) {
                    fn_27_10424(self + 0x12C8, -1);
                }
                fn_27_2DBA8C(self + 0x1130, -1);
                fn_27_2DB610(self + 0x101C, -1);
                fn_27_2F80A0(self + 0xE74, -1);
                fn_27_1E09C4(self + 0xDD0, -1);
                if (self + 0xD9C) {
                    fn_27_A1E80(self + 0xD9C, -1);
                }
                if (self + 0xD84) {
                    fn_27_5AE44(self + 0xD84, -1);
                }
                if (self + 0xC20) {
                    fn_27_6A3D8(self + 0xD30, -1);
                }
                if (self + 0xBB8) {
                    fn_27_565F0(self + 0xBC4, -1);
                }
                if (self + 0xBAC) {
                    fn_27_6880C(self + 0xBB0, -1);
                }
                if (self + 0xB84) {
                    __dt__16soStopModuleImplFv(self + 0xB84, -1);
                }
                if (self + 0xB14) {
                    fn_27_B5324(self + 0xB34, -1);
                }
                if (self + 0xAD8) {
                    fn_27_3544C(self + 0xAD8, -1);
                }
                if (self + 0xA20) {
                    __dt__19soPostureModuleImplFv(self + 0xA5C, -1);
                    if (self + 0xA20 && self + 0xA20) {
                        __destroy_arr(self + 0xA2C, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_2F822C(self + 0x85C, -1);
                if (self + 0x67C) {
                    __dt__17soModelModuleImplFv(self + 0x790, -1);
                }
                if (self + 0x64C) {
                    __dt__20soResourceModuleImplFv(self + 0x664, -1);
                }
                if (self + 0x624) {
                    __dt__16soHeapModuleImplFv(self + 0x624, -1);
                }
                __dt__16soModuleAccesserFv(self + 0x544, -1);
                fn_27_2ECF44(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
