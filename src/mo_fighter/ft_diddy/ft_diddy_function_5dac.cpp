#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_3D54(void*, short);

extern "C" void* fn_115_5DAC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_115_3D54(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
