#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2E7480(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_2ECF44(void*, short);
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

extern "C" void* fn_27_2F1E60(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x1878, -1);
            if (self + 0xCC) {
                if (self + 0x1520) {
                    if (self + 0x17F0 && self + 0x17F0) {
                        __dt__16acCmdInterpreterFv(self + 0x17F0, 0);
                    }
                    if (self + 0x173C) {
                        if (self + 0x17A0) {
                            __dt__16acCmdInterpreterFv(self + 0x17A0, 0);
                        }
                    }
                    if (self + 0x1688) {
                        if (self + 0x16EC) {
                            __dt__16acCmdInterpreterFv(self + 0x16EC, 0);
                        }
                    }
                    if (self + 0x15D4) {
                        if (self + 0x1638) {
                            __dt__16acCmdInterpreterFv(self + 0x1638, 0);
                        }
                    }
                    if (self + 0x1520) {
                        if (self + 0x1584) {
                            __dt__16acCmdInterpreterFv(self + 0x1584, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x14DC) fn_27_63EBC(self + 0x14DC, -1);
                    if (self + 0x14C4) fn_27_5C674(self + 0x14C4, -1);
                    fn_27_2DBA8C(self + 0x1328, -1);
                    fn_27_2DB610(self + 0x1214, -1);
                    fn_27_2E7480(self + 0x1090, -1);
                    fn_27_1E09C4(self + 0xFEC, -1);
                    if (self + 0xFB8) fn_27_A1E80(self + 0xFB8, -1);
                    if (self + 0xE50) fn_27_6A3D8(self + 0xF60, -1);
                    if (self + 0xDE8) fn_27_565F0(self + 0xDF4, -1);
                    if (self + 0xDDC) fn_27_6880C(self + 0xDE0, -1);
                    if (self + 0xDB4) __dt__16soStopModuleImplFv(self + 0xDB4, -1);
                    fn_27_2DAF88(self + 0xBE4, -1);
                    if (self + 0xB80) fn_27_B5324(self + 0xBA0, -1);
                    if (self + 0xB44) fn_27_3544C(self + 0xB44, -1);
                    if (self + 0xA9C) {
                        fn_27_25740(self + 0xAEC, -1);
                        if (self + 0xA9C) {
                            __destroy_arr(self + 0xAA8, fn_27_2E888, 0x44, 1);
                        }
                    }
                    if (self + 0x9E8) {
                        __dt__19soPostureModuleImplFv(self + 0xA24, -1);
                        if (self + 0x9E8 && self + 0x9E8) {
                            __destroy_arr(self + 0x9F4, fn_27_25290, 0x30, 1);
                        }
                    }
                    if (self + 0x85C) fn_27_13C90(self + 0x878, -1);
                    if (self + 0x67C) __dt__17soModelModuleImplFv(self + 0x790, -1);
                    if (self + 0x64C) __dt__20soResourceModuleImplFv(self + 0x664, -1);
                    if (self + 0x624) __dt__16soHeapModuleImplFv(self + 0x624, -1);
                    __dt__16soModuleAccesserFv(self + 0x544, -1);
                    fn_27_2ECF44(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
