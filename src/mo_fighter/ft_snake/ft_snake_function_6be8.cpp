#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_6C64(void* object, short deleting);
extern "C" void fn_122_6F14(void* object, short deleting);

extern "C" void* fn_122_6BE8(void* object, short deleting) {
    if (object != 0) {
        fn_122_6C64((unsigned char*)object + 0x132E0, -1);
        if (object != 0) {
            fn_122_6F14(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
