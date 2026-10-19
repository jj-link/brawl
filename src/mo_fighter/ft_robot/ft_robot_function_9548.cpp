#pragma force_active on
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_120_1988(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_9548(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x12290, -1);
        fn_120_1988(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
