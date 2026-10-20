#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_116_590C(void*, short);
void operator delete(void*);

extern "C" void* fn_116_5894(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x4B8, -1);
        if (object != 0) {
            fn_116_590C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
