#pragma force_active on
extern "C" {
void fn_27_1DBB60(void*, int);
void __dt__16acCmdInterpreterFv(void*, short);
void fn_27_63EBC(void*, int);
void fn_27_5C674(void*, int);
void fn_27_BED74(void*, int);
void fn_27_2DBA8C(void*, int);
void fn_27_2DB610(void*, int);
void fn_27_2F5BA0(void*, int);
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
void fn_27_2F581C(void*, int);
void __dt__17soModelModuleImplFv(void*, short);
void __dt__20soResourceModuleImplFv(void*, short);
void __dt__16soHeapModuleImplFv(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_27_2F5200(void*, int);
void fn_27_1D81C8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_2F7348(char* self, int flags) {
    if (self) {
        fn_27_1DBB60(self + 0x17B8, -1);
        if (self + 0xCC) {
            if (self + 0x1460) {
                if (self + 0x1730 && self + 0x1730) {
                    __dt__16acCmdInterpreterFv(self + 0x1730, 0);
                }
                if (self + 0x167C) {
                    if (self + 0x16E0) {
                        __dt__16acCmdInterpreterFv(self + 0x16E0, 0);
                    }
                }
                if (self + 0x15C8) {
                    if (self + 0x162C) {
                        __dt__16acCmdInterpreterFv(self + 0x162C, 0);
                    }
                }
                if (self + 0x1514) {
                    if (self + 0x1578) {
                        __dt__16acCmdInterpreterFv(self + 0x1578, 0);
                    }
                }
                if (self + 0x1460) {
                    if (self + 0x14C4) {
                        __dt__16acCmdInterpreterFv(self + 0x14C4, 0);
                    }
                }
            }
            if (self + 0xCC) {
                if (self + 0x141C) {
                    fn_27_63EBC(self + 0x141C, -1);
                }
                if (self + 0x1404) {
                    fn_27_5C674(self + 0x1404, -1);
                }
                if (self + 0x12AC) {
                    fn_27_BED74(self + 0x12AC, -1);
                }
                fn_27_2DBA8C(self + 0x1114, -1);
                fn_27_2DB610(self + 0x1000, -1);
                fn_27_2F5BA0(self + 0xE80, -1);
                fn_27_1E09C4(self + 0xDDC, -1);
                if (self + 0xDA8) {
                    fn_27_A1E80(self + 0xDA8, -1);
                }
                if (self + 0xD90) {
                    fn_27_5AE44(self + 0xD90, -1);
                }
                if (self + 0xC2C) {
                    fn_27_6A3D8(self + 0xD3C, -1);
                }
                if (self + 0xBC4) {
                    fn_27_565F0(self + 0xBD0, -1);
                }
                if (self + 0xBB8) {
                    fn_27_6880C(self + 0xBBC, -1);
                }
                if (self + 0xB90) {
                    __dt__16soStopModuleImplFv(self + 0xB90, -1);
                }
                if (self + 0xB20) {
                    fn_27_B5324(self + 0xB40, -1);
                }
                if (self + 0xAE4) {
                    fn_27_3544C(self + 0xAE4, -1);
                }
                if (self + 0xA2C) {
                    __dt__19soPostureModuleImplFv(self + 0xA68, -1);
                    if (self + 0xA2C && self + 0xA2C) {
                        __destroy_arr(self + 0xA38, fn_27_25290, 0x30, 1);
                    }
                }
                fn_27_2F581C(self + 0x868, -1);
                if (self + 0x688) {
                    __dt__17soModelModuleImplFv(self + 0x79C, -1);
                }
                if (self + 0x658) {
                    __dt__20soResourceModuleImplFv(self + 0x670, -1);
                }
                if (self + 0x630) {
                    __dt__16soHeapModuleImplFv(self + 0x630, -1);
                }
                __dt__16soModuleAccesserFv(self + 0x550, -1);
                fn_27_2F5200(self + 0xCC, -1);
            }
        }
        fn_27_1D81C8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
