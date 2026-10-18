#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_37C8(void*, short);

extern "C" void* fn_95_197F8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_95_37C8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
