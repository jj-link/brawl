#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_27A04(void* p, short flag) {
    if (p != 0) {
        fn_27_6A3D8(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
