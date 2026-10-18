#pragma force_active on
extern "C" void* fn_99_9DB4(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_99_9E14(void* object, short deleting) {
    if (object) {
        fn_99_9DB4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
