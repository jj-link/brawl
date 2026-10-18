#pragma force_active on
extern "C" void fn_120_3A1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12E38(void* object, short deleting) {
    if (object != 0) {
        fn_120_3A1C(static_cast<unsigned char*>(object) + 0x38, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
