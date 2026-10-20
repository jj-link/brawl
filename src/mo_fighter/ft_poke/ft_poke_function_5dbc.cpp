#pragma force_active on
extern "C" {
void* fn_27_D2904(void* member, short deleteFlag);
void fn_116_5E34(void* object, short deleteFlag);
void __dl__FPv(void*);
}

extern "C" void* fn_116_5DBC(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_116_5E34(object, 0);
        }
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
