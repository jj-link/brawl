#pragma force_active on
void operator delete(void*);

extern "C" void* fn_122_48DC(void*, short);

extern "C" void* fn_122_A3D0(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_122_48DC(object, baseDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
