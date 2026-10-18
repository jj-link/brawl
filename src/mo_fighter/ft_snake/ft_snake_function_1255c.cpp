#pragma force_active on
extern "C" void fn_122_124FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1255C(void* object, short deleting) {
    if (object != 0) {
        fn_122_124FC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
