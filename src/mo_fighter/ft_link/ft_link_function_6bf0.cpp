#pragma force_active on
extern "C" void* fn_93_6B90(void*, short);
extern "C" void* fn_93_6ACC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_6BF0(void* object, short deleting) {
    if (object != 0) {
        fn_93_6B90(static_cast<unsigned char*>(object) + 0x16D8, -1);
        fn_93_6ACC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
