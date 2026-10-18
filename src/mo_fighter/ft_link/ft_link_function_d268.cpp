#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_7100(void*, short);

extern "C" void* fn_93_D268(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_93_7100(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
