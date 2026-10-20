#pragma force_active on
extern "C" void* fn_100_B514(void* object, short shouldDelete);
extern "C" void fn_100_B3E0(void* object, short param);

extern "C" void* fn_100_B574(void* object, short shouldDelete) {
    if (object != 0) {
        fn_100_B514((char*)object + 0x1C8, -1);
        if (object != 0) {
            fn_100_B3E0(object, 0);
        }
        if (shouldDelete > 0) {
            operator delete(object);
        }
    }
    return object;
}
