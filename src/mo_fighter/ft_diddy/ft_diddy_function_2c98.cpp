#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_2C98(void* p, int count) {
    if (p != 0) {
        fn_27_C21DC(p, -1);
        if ((short)count > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
