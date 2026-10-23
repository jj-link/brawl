#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_106_4CD0(void*, short);
extern "C" void* fn_106_4D3C(void*, short);
extern "C" void* fn_106_4D98(void*, short);
extern "C" void* fn_106_4DF4(void*, short);
extern "C" void* fn_106_4E50(void*, short);
extern "C" void* fn_106_4EAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4C1C(void* self, short del) {
    if (self) {
        fn_27_13C90((char*)self + 0x224, -1);
        fn_106_4CD0((char*)self + 0x1E8, -1);
        fn_27_21038((char*)self + 0x1D8, -1);
        fn_106_4D3C((char*)self + 0x1B8, -1);
        fn_106_4D98((char*)self + 0x198, -1);
        fn_106_4DF4((char*)self + 0x160, -1);
        fn_106_4E50((char*)self + 0xC4, -1);
        fn_106_4EAC(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
