#pragma force_active on
extern "C" void fn_122_7B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_7AA8(void* object, short deleting) {
    if (object != 0) {
        fn_122_7B08(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
