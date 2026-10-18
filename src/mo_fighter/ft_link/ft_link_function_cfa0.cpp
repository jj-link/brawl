#pragma force_active on
extern "C" void* fn_93_CF44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_CFA0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_CF44(members + 4, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
