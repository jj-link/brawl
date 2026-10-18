#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_4554(void*, short);

extern "C" void* fn_107_7F38(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_107_4554(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
