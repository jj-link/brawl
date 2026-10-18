#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_3944(void*, short);

extern "C" void* fn_107_188B4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_107_3944(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
