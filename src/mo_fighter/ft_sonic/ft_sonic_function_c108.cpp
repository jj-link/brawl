#pragma force_active on
extern "C" void* fn_123_396C(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_123_C108(void* object, short deleting) {
    if (object != 0) {
        fn_123_396C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
