#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_123_54EC(void*, short);

extern "C" void* fn_123_5474(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x4B8, -1);
        if (object != 0) {
            fn_123_54EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
