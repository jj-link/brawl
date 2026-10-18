#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_1213C(void*, short);

extern "C" void* fn_117_120DC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_1213C(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
