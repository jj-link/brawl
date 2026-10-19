#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_644C(void* obj, short flag) {
    if (obj != 0) {
        fn_27_BED74(obj, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
