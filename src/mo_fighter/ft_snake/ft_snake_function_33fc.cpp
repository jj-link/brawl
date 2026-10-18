#pragma force_active on
extern "C" void fn_122_345C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_33FC(void* object, short deleting) {
    if (object != 0) {
        fn_122_345C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
