#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_C4160(void*, int);
extern "C" void* fn_96_1DF5C(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_96_1DE6C(void* object, short deleting) {
    if (object != 0) {
        __destroy_arr(static_cast<unsigned char*>(object) + 0xC, fn_27_C4160, 0x60, 4);
        fn_96_1DF5C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
