#pragma force_active on
extern "C" void* fn_99_3308(void*, short);
extern "C" void* fn_99_3434(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_3298(void* object, short deleting) {
    if (object) {
        fn_99_3308(static_cast<unsigned char*>(object) + 0x20A0, -1);
        fn_99_3434(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
