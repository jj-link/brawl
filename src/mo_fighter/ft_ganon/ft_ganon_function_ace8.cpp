#pragma force_active on
extern "C" void fn_109_AC88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_ACE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_109_AC88(members + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
