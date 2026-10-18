#pragma force_active on
void operator delete(void*);

extern "C" void fn_116_1E2DC(void*, short);

extern "C" void* fn_116_1E27C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_1E2DC(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
