#pragma force_active on
extern "C" {
void* fn_100_B380(void* object, short shouldDelete);
void fn_100_B248(void* object, short shouldDelete);
}

extern "C" void* fn_100_B3E0(void* object, short shouldDelete) {
    if (object != 0) {
        fn_100_B380((char*)object + 0x17c, (short)-1);
        if (object != 0) {
            fn_100_B248(object, (short)0);
        }
        if (shouldDelete > 0) {
            operator delete(object);
        }
    }
    return object;
}
