#pragma force_active on
extern "C" void* fn_95_5938(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_5C48(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_95_5938(static_cast<unsigned char*>(object) + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
