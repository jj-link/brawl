#pragma force_active on
void operator delete(void*);
extern "C" void fn_117_4A04(void*, short);

extern "C" void* fn_117_49A4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_4A04(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
