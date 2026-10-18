#pragma force_active on
void operator delete(void*);

extern "C" void* fn_96_84BC(void*, short);

extern "C" void* fn_96_11B50(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_96_84BC(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
