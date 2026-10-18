#pragma force_active on
extern "C" void* fn_27_14B698(void* member, short deleteFlag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_92_6C24(void* object, short memberDeleteFlag) {
    if (object != 0) {
        fn_27_14B698(object, -1);
        if (memberDeleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
