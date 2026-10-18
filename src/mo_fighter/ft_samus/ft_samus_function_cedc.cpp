#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_4750(void*, short);
extern "C" void* fn_94_CEDC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_94_4750(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
