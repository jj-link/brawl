#pragma force_active on
extern "C" {
void* fn_27_CC7EC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_6914(void* object, int deleteFlag) {
    if (object != 0) {
        fn_27_CC7EC(object, -1);
        if ((short)deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
