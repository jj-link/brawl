#pragma force_active on
extern "C" void* fn_119_AEA8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_AF08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_119_AEA8(members + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
