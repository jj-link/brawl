#pragma force_active on
void operator delete(void*);

extern "C" void fn_112_C7A4(void*, short);
extern "C" void fn_112_C66C(void*, short);

extern "C" void* fn_112_C804(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_C7A4(members + 0x17C, memberDeleting);
        if (object != 0) {
            fn_112_C66C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
