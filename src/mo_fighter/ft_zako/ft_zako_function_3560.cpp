#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_126_35D8(void* object, short flag);

extern "C" void* fn_126_3560(char* object, short deleteFlag) {
    if (object != 0) {
        fn_27_1A1B88(object + 0x48c, -1);
        if (object != 0) {
            fn_126_35D8(object, 0);
        }
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
