#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_6B50(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_CC7EC(object, -1);
        if (deleteFlag > 0)
            __dl__FPv(object);
    }
    return object;
}
