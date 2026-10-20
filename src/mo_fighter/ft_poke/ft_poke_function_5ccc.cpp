#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_116_5D44(void*, short);

extern "C" void* fn_116_5CCC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x1FC, -1);
        if (object != 0) {
            fn_116_5D44(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
