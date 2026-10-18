#pragma force_active on
extern "C" void fn_99_A1FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A25C(void* object, short deleting) {
    if (object) {
        fn_99_A1FC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
