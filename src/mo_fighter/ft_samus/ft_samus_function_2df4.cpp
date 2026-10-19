#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_2DF4(void* obj, short flag) {
    if (obj != 0) {
        fn_27_B64B8(obj, -1);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
