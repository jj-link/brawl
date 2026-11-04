#pragma force_active on
extern "C" {
void* fn_27_1DBB60(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_36A0A4(void*, short);
void* fn_27_1E2F5C(void*, short);
void* fn_27_36A100(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_36A238(void*, short);
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

extern "C" void* fn_27_36D70C(char* self, int flag) {
    if (self) {
        if (self) {
            fn_27_1DBB60(self + 0x15CC, -1);
            if (self + 0xCC) {
                if (self + 0x12A8) {
                    if (self + 0x1544 && self + 0x1544) {
                        __dt__16acCmdInterpreterFv(self + 0x1544, 0);
                    }
                    if (self + 0x1490) {
                        if (self + 0x14F4) {
                            __dt__16acCmdInterpreterFv(self + 0x14F4, 0);
                        }
                    }
                    if (self + 0x13DC) {
                        if (self + 0x1440) {
                            __dt__16acCmdInterpreterFv(self + 0x1440, 0);
                        }
                    }
                    if (self + 0x1328) {
                        if (self + 0x138C) {
                            __dt__16acCmdInterpreterFv(self + 0x138C, 0);
                        }
                    }
                    if (self + 0x12A8) {
                        if (self + 0x12D8) {
                            __dt__16acCmdInterpreterFv(self + 0x12D8, 0);
                        }
                    }
                }
                if (self + 0xCC) {
                    if (self + 0x128C) fn_27_C31CC(self + 0x128C, -1);
                    if (self + 0x124C) fn_27_63EBC(self + 0x124C, -1);
                    if (self + 0x1234) fn_27_5C674(self + 0x1234, -1);
                    fn_27_36A0A4(self + 0x10DC, -1);
                    fn_27_1E2F5C(self + 0xFFC, -1);
                    fn_27_36A100(self + 0xF24, -1);
                    fn_27_1E09C4(self + 0xE80, -1);
                    if (self + 0xE4C) fn_27_A1E80(self + 0xE4C, -1);
                    if (self + 0xCE4) fn_27_6A3D8(self + 0xDF4, -1);
                    if (self + 0xCD4) fn_27_6880C(self + 0xCD8, -1);
                    if (self + 0xCAC) __dt__16soStopModuleImplFv(self + 0xCAC, -1);
                    fn_27_2DAF88(self + 0xADC, -1);
                    if (self + 0xA78) fn_27_B5324(self + 0xA98, -1);
                    if (self + 0xA3C) fn_27_3544C(self + 0xA3C, -1);
                    if (self + 0x994) {
                        fn_27_25740(self + 0x9E4, -1);
                        if (self + 0x994) __destroy_arr(self + 0x9A0, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0x8E0) {
                        __dt__19soPostureModuleImplFv(self + 0x91C, -1);
                        if (self + 0x8E0 && self + 0x8E0) __destroy_arr(self + 0x8EC, fn_27_25290, 0x30, 1);
                    }
                    if (self + 0x754) fn_27_13C90(self + 0x770, -1);
                    if (self + 0x644) __dt__17soModelModuleImplFv(self + 0x688, -1);
                    if (self + 0x618) __dt__16soHeapModuleImplFv(self + 0x618, -1);
                    __dt__16soModuleAccesserFv(self + 0x538, -1);
                    fn_27_36A238(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
