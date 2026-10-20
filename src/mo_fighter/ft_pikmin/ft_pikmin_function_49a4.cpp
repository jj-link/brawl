#pragma force_active on
extern "C" void* fn_27_1A3530(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_49A4(void* p, short flag) {
    if (p != 0) {
        fn_27_1A3530(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
