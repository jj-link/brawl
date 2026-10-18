#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_5860(void*, short);

extern "C" void* fn_96_58D8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_96_5860(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
