#pragma force_active on
extern "C" void fn_95_542C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_53CC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_95_542C(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
