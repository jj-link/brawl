#pragma force_active on
extern "C" {
void* fn_27_14B698(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_119_5610(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_14B698(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
