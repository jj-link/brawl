#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_27_19EB34(void*, short);
extern "C" void* fn_27_1A4E94(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_1A798(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_27_19EB34(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_1A4E94(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
