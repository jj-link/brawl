#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_2DB610(void*, short);
void* fn_27_308438(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_327AE8(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_3085C4(void*, short);
void* fn_27_2DA6B8(void*, short);
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

extern "C" void* fn_27_3A49B8(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x1FA0, -1);
            if (self + 0xCC) {
                if (self + 0x19F0) {
                    if (self + 0x1EA0 && self + 0x1EA0) {
                        __dt__16acCmdInterpreterFv(self + 0x1EA0, 0);
                    }
                    if (self + 0x1D74) {
                        if (self + 0x1E50) {
                            __dt__16acCmdInterpreterFv(self + 0x1E50, 0);
                        }
                    }
                    if (self + 0x1C48) {
                        if (self + 0x1D24) {
                            __dt__16acCmdInterpreterFv(self + 0x1D24, 0);
                        }
                    }
                    if (self + 0x1B1C) {
                        if (self + 0x1BF8) {
                            __dt__16acCmdInterpreterFv(self + 0x1BF8, 0);
                        }
                    }
                    if (self + 0x19F0) {
                        if (self + 0x1ACC) {
                            __dt__16acCmdInterpreterFv(self + 0x1ACC, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x19D4) fn_27_C31CC(self + 0x19D4, -1);
                    if (self + 0x1994) fn_27_63EBC(self + 0x1994, -1);
                    if (self + 0x197C) fn_27_5C674(self + 0x197C, -1);
                    fn_27_2DBA8C(self + 0x17E0, -1);
                    fn_27_2DB610(self + 0x16CC, -1);
                    fn_27_308438(self + 0x1508, -1);
                    fn_27_1E09C4(self + 0x1464, -1);
                    if (self + 0x1430) fn_27_A1E80(self + 0x1430, -1);
                    if (self + 0x1418) fn_27_5AE44(self + 0x1418, -1);
                    if (self + 0x12B4) fn_27_6A3D8(self + 0x13C4, -1);
                    if (self + 0x124C) fn_27_565F0(self + 0x1258, -1);
                    if (self + 0x1240) fn_27_6880C(self + 0x1244, -1);
                    if (self + 0x1218) __dt__16soStopModuleImplFv(self + 0x1218, -1);
                    fn_27_327AE8(self + 0xFB8, -1);
                    if (self + 0xF54) fn_27_B5324(self + 0xF74, -1);
                    if (self + 0xF18) fn_27_3544C(self + 0xF18, -1);
                    if (self + 0xE70) {
                        fn_27_25740(self + 0xEC0, -1);
                        if (self + 0xE70) __destroy_arr(self + 0xE7C, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0xDBC) {
                        __dt__19soPostureModuleImplFv(self + 0xDF8, -1);
                        if (self + 0xDBC && self + 0xDBC) __destroy_arr(self + 0xDC8, fn_27_25290, 0x30, 1);
                    }
                    fn_27_3085C4(self + 0xBB0, -1);
                    if (self + 0x9D0) __dt__17soModelModuleImplFv(self + 0xAE4, -1);
                    if (self + 0x9A4) __dt__16soHeapModuleImplFv(self + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(self + 0x8C4, -1);
                    fn_27_2DA6B8(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
