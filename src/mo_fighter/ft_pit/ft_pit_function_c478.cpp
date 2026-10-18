#pragma force_active on
extern "C" void fn_112_C418(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C478(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_C418(member + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
