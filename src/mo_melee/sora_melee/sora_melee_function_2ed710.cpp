#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_2E7480(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
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

extern "C" void* fn_27_2ED710(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x18A4, -1);
            if (self + 0xCC) {
                if (self + 0x154C) {
                    if (self + 0x181C && self + 0x181C) {
                        __dt__16acCmdInterpreterFv(self + 0x181C, 0);
                    }
                    if (self + 0x1768) {
                        if (self + 0x17CC) {
                            __dt__16acCmdInterpreterFv(self + 0x17CC, 0);
                        }
                    }
                    if (self + 0x16B4) {
                        if (self + 0x1718) {
                            __dt__16acCmdInterpreterFv(self + 0x1718, 0);
                        }
                    }
                    if (self + 0x1600) {
                        if (self + 0x1664) {
                            __dt__16acCmdInterpreterFv(self + 0x1664, 0);
                        }
                    }
                    if (self + 0x154C) {
                        if (self + 0x15B0) {
                            __dt__16acCmdInterpreterFv(self + 0x15B0, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x1530) fn_27_C31CC(self + 0x1530, -1);
                    if (self + 0x14F0) fn_27_63EBC(self + 0x14F0, -1);
                    if (self + 0x14D8) fn_27_5C674(self + 0x14D8, -1);
                    fn_27_2DBA8C(self + 0x133C, -1);
                    fn_27_2DB610(self + 0x1228, -1);
                    fn_27_2E7480(self + 0x10A4, -1);
                    fn_27_1E09C4(self + 0x1000, -1);
                    if (self + 0xFCC) fn_27_A1E80(self + 0xFCC, -1);
                    if (self + 0xFB4) fn_27_5AE44(self + 0xFB4, -1);
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