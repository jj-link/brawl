#pragma force_active on
extern "C" void* fn_106_3430(void*, short);
extern "C" void* fn_106_34B4(void*, short);
extern "C" void* fn_106_3514(void*, short);
extern "C" void* fn_106_3570(void*, short);
extern "C" void* fn_106_4028(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_3394(void* self, short del) {
    if (self) {
        fn_106_3430((char*)self + 0xE08, -1);
        fn_106_34B4((char*)self + 0xDF4, -1);
        fn_106_3514((char*)self + 0x964, -1);
        fn_106_3570((char*)self + 0xF0, -1);
        fn_106_4028((char*)self + 0x10, -1);
        fn_27_C74E8(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
