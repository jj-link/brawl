#pragma force_active on

extern "C" void* fn_94_367C(void*, short);
extern "C" void* fn_94_3748(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_36DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_367C(members + 0x1AA8, memberDeleting);
        fn_94_3748(members + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
