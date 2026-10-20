#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_100_52D0(void* object, short flag);

extern "C" void* fn_100_5258(char* object, short deleteFlag) {
    if (object != 0) {
        fn_27_1A1B88(object + 0x48c, -1);
        if (object != 0) {
            fn_100_52D0(object, 0);
        }
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
