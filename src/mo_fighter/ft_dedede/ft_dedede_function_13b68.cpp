#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_13B28(void*, short);

extern "C" void* fn_117_13B68(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_117_13B28(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
