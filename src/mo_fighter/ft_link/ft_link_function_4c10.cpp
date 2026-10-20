#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_93_4B98(void*, short);

extern "C" void* fn_93_4C10(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8((char*)object + 0x11C, -1);
        if (object != 0) {
            fn_93_4B98(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
