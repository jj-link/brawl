#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_C5B8(void* object, short deleting);
extern "C" void fn_115_C484(void* object, short deleting);

extern "C" void* fn_115_C618(void* object, short deleting) {
    if (object != 0) {
        fn_115_C5B8((unsigned char*)object + 0x1C8, -1);
        if (object != 0) {
            fn_115_C484(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
