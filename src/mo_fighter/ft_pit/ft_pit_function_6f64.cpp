#pragma force_active on
void operator delete(void*);

extern "C" void* fn_112_3BA4(void*, short);

extern "C" void* fn_112_6F64(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_112_3BA4(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
