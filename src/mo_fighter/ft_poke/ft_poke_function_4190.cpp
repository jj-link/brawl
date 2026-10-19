#pragma force_active on
extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_4190(void* obj, short flag) {
    if (obj != 0) {
        fn_27_3544C(obj, -1);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
