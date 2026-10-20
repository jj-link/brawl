#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void* member, short deleteFlag);
void fn_100_58E8(void* object, short deleteFlag);
void __dl__FPv(void* p);
}

extern "C" void* fn_100_5870(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_100_58E8(object, 0);
        }
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
