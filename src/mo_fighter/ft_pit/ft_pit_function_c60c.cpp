#pragma force_active on
extern "C" void fn_112_C5AC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C60C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_C5AC(members + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
