#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_88E8(void*, short);

extern "C" void* fn_96_2AAC4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_96_88E8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
