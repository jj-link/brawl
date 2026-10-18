#pragma force_active on
void operator delete(void*);

extern "C" void* fn_96_1E0BC(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_96_1DF5C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_96_1E0BC(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
