#pragma force_active on
extern "C" void* fn_116_C910(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C96C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_116_C910(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
