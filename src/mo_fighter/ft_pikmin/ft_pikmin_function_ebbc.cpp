#pragma force_active on
extern "C" void fn_113_EB5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_EBBC(void* object, short deleting) {
    if (object != 0) {
        fn_113_EB5C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
