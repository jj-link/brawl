#pragma force_active on
extern "C" void* fn_27_5BFA0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_2A08(void* obj, short val) {
    if (obj != 0) {
        fn_27_5BFA0(obj, -1);
        if (val > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
