#pragma force_active on
extern "C" void* fn_27_1A2524(void*, short);
extern "C" void* fn_108_3F20(void* ptr, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_705C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_108_3F20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
