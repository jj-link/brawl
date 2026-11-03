#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_731C[];
extern char lbl_27_data_21018[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_2E888(void*, int);
void fn_27_25290(void*, int);
void fn_27_86D4C(void*, int);
void* fn_27_C31CC(void*, short);
void* fn_27_63EBC(void*, short);
void* fn_27_5C674(void*, short);
void* fn_27_ACC5C(void*, short);
void* fn_27_2DBA8C(void*, short);
void* fn_27_348BF4(void*, short);
void* fn_27_2E2534(void*, short);
void* fn_27_1E09C4(void*, short);
void* fn_27_A1E80(void*, short);
void* fn_27_5AE44(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_565F0(void*, short);
void* fn_27_6880C(void*, short);
void* fn_27_5CC1C(void*, short);
void* fn_27_348D5C(void*, short);
void* fn_27_2DAF88(void*, short);
void* fn_27_B5324(void*, short);
void* fn_27_3544C(void*, short);
void* fn_27_25740(void*, short);
void* fn_27_3085C4(void*, short);
void* fn_27_348E18(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16acCmdInterpreterFv(void*, short);
void* __dt__16soStopModuleImplFv(void*, short);
void* __dt__19soPostureModuleImplFv(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* __dt__20soResourceModuleImplFv(void*, short);
void* __dt__16soHeapModuleImplFv(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

struct EventSystem {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool isExist(s16);
};

struct EventManager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16, s16);
};

extern "C" void* fn_27_34C57C(char* self, int flag) {
    if (self) {
        if (self + 0x2350 && self + 0x2350) {
            s16 id = *(s16*)(self + 0x2354);
            *(void**)(self + 0x2350) = lbl_27_data_731C;
            if (((EventSystem*)getInstance__13soEventSystemFv())->isExist(id) == 1) {
                ((EventManager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)(self + 0x2354)))->f3(*(s16*)(self + 0x2356), *(s16*)(self + 0x2358));
            }
            *(s16*)(self + 0x2358) = -1;
            *(s16*)(self + 0x2354) = -1;
        }
        if (self + 0x2344 && self + 0x2344) {
            s16 id = *(s16*)(self + 0x2348);
            *(void**)(self + 0x2344) = lbl_27_data_21018;
            if (((EventSystem*)getInstance__13soEventSystemFv())->isExist(id) == 1) {
                ((EventManager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)(self + 0x2348)))->f3(*(s16*)(self + 0x234A), *(s16*)(self + 0x234C));
            }
            *(s16*)(self + 0x234C) = -1;
            *(s16*)(self + 0x2348) = -1;
        }
        if (self) {
            if (self + 0xCC) {
                if (self + 0x1D90) {
                    if (self + 0x2240 && self + 0x2240) __dt__16acCmdInterpreterFv(self + 0x2240, 0);
                    if (self + 0x2114) { if (self + 0x21F0) __dt__16acCmdInterpreterFv(self + 0x21F0, 0); }
                    if (self + 0x1FE8) { if (self + 0x20C4) __dt__16acCmdInterpreterFv(self + 0x20C4, 0); }
                    if (self + 0x1EBC) { if (self + 0x1F98) __dt__16acCmdInterpreterFv(self + 0x1F98, 0); }
                    if (self + 0x1D90) { if (self + 0x1E6C) __dt__16acCmdInterpreterFv(self + 0x1E6C, 0); }
                }
                if (self + 0xCC) {
                    if (self + 0x1D74) fn_27_C31CC(self + 0x1D74, -1);
                    if (self + 0x1D34) fn_27_63EBC(self + 0x1D34, -1);
                    if (self + 0x1D1C) fn_27_5C674(self + 0x1D1C, -1);
                    if (self + 0x1C94) fn_27_ACC5C(self + 0x1C94, -1);
                    fn_27_2DBA8C(self + 0x1AFC, -1);
                    fn_27_348BF4(self + 0x1974, -1);
                    fn_27_2E2534(self + 0x17AC, -1);
                    fn_27_1E09C4(self + 0x1708, -1);
                    if (self + 0x16D4) fn_27_A1E80(self + 0x16D4, -1);
                    if (self + 0x16BC) fn_27_5AE44(self + 0x16BC, -1);
                    if (self + 0x1558) fn_27_6A3D8(self + 0x1668, -1);
                    if (self + 0x14F0) fn_27_565F0(self + 0x14FC, -1);
                    if (self + 0x14E4) fn_27_6880C(self + 0x14E8, -1);
                    if (self + 0x14BC) __dt__16soStopModuleImplFv(self + 0x14BC, -1);
                    if (self + 0x1360) {
                        fn_27_5CC1C(self + 0x140C, -1);
                        if (self + 0x1360 && self + 0x1360) __destroy_arr(self + 0x136C, fn_27_86D4C, 0xA0, 1);
                    }
                    fn_27_348D5C(self + 0x11B4, -1);
                    fn_27_2DAF88(self + 0xFF0, -1);
                    if (self + 0xF8C) fn_27_B5324(self + 0xFAC, -1);
                    if (self + 0xF50) fn_27_3544C(self + 0xF50, -1);
                    if (self + 0xEA8) {
                        fn_27_25740(self + 0xEF8, -1);
                        if (self + 0xEA8) __destroy_arr(self + 0xEB4, fn_27_2E888, 0x44, 1);
                    }
                    if (self + 0xDF4) {
                        __dt__19soPostureModuleImplFv(self + 0xE30, -1);
                        if (self + 0xDF4 && self + 0xDF4) __destroy_arr(self + 0xE00, fn_27_25290, 0x30, 1);
                    }
                    fn_27_3085C4(self + 0xBE8, -1);
                    if (self + 0xA08) __dt__17soModelModuleImplFv(self + 0xB1C, -1);
                    if (self + 0x9D8) __dt__20soResourceModuleImplFv(self + 0x9F0, -1);
                    if (self + 0x9B0) __dt__16soHeapModuleImplFv(self + 0x9B0, -1);
                    __dt__16soModuleAccesserFv(self + 0x8D0, -1);
                    fn_27_348E18(self + 0xCC, -1);
                }
            }
            fn_27_1D81C8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
