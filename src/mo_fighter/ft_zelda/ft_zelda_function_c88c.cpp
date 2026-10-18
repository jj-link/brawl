#pragma force_active on
void operator delete(void*);

extern "C" void* fn_104_38A0(void*, short);

extern "C" void* fn_104_C88C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_104_38A0(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
