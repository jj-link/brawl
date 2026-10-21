#pragma force_active on
extern "C" void* fn_116_3884(void* self, short deleting);
extern "C" void* fn_116_12F0C(void* object, short deleting);
extern "C" void* fn_116_12F98(void* object, short deleting);
extern "C" void* fn_116_13024(void* object, short deleting);
extern "C" void* fn_116_130B0(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_116_12E7C(void* object, short deleting) {
    if (object != 0) {
        short minus_one = -1;
        fn_116_3884((char*)object + 0x29c, minus_one);
        fn_116_12F0C((char*)object + 0x1e8, minus_one);
        fn_116_12F98((char*)object + 0x134, minus_one);
        fn_116_13024((char*)object + 0x80, minus_one);
        fn_116_130B0(object, minus_one);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
