#pragma force_active on

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_105_7A08(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_105_7A74(void*, short);
extern "C" void* fn_105_7AD0(void*, short);
extern "C" void* fn_105_7B2C(void*, short);
extern "C" void* fn_105_7B88(void*, short);
extern "C" void* fn_105_7BE4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_7954(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_13C90(p + 0x224, -1);
        fn_105_7A08(p + 0x1E8, -1);
        fn_27_21038(p + 0x1D8, -1);
        fn_105_7A74(p + 0x1B8, -1);
        fn_105_7AD0(p + 0x198, -1);
        fn_105_7B2C(p + 0x160, -1);
        fn_105_7B88(p + 0xC4, -1);
        fn_105_7BE4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
