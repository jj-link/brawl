#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_17FD8(void*, short);

extern "C" void* fn_117_17F7C(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_117_17FD8(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
