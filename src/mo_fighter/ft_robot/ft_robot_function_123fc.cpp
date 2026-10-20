#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_120_12384(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_123FC(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9C, -1);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, -1);
        fn_120_12384(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
