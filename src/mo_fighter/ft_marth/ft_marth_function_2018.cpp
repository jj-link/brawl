#pragma force_active on
extern "C" void* fn_106_20F0(void*, short);
extern "C" void* fn_106_22B4(void*, short);
extern "C" void* fn_106_237C(void*, short);
extern "C" void* fn_106_2408(void*, short);
extern "C" void* fn_106_2494(void*, short);
extern "C" void* fn_106_2520(void*, short);
extern "C" void* fn_106_25AC(void*, short);
extern "C" void* fn_106_2638(void*, short);
extern "C" void* fn_106_26C4(void*, short);
extern "C" void* fn_106_2750(void*, short);
extern "C" void* fn_106_27DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_2018(void* self, short del) {
    if (self) {
        fn_106_20F0((char*)self + 0x14C0, -1);
        fn_106_22B4((char*)self + 0x139C, -1);
        fn_106_237C((char*)self + 0x1270, -1);
        fn_106_2408((char*)self + 0x1144, -1);
        fn_106_2494((char*)self + 0x1018, -1);
        fn_106_2520((char*)self + 0xEEC, -1);
        fn_106_25AC((char*)self + 0xDC0, -1);
        fn_106_2638((char*)self + 0xC94, -1);
        fn_106_26C4((char*)self + 0xB68, -1);
        fn_106_2750((char*)self + 0xA3C, -1);
        fn_106_27DC(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
