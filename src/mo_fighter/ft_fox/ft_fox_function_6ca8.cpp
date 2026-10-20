#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_97_6D20(void*, short);

extern "C" void* fn_97_6CA8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_97_6D20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
