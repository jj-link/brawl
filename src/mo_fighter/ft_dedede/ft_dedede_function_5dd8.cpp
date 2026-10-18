#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_5E34(void*, short);

extern "C" void* fn_117_5DD8(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_117_5E34(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
