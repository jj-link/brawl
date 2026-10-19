#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_2CF4(void* p, short flag) {
    if (p != 0) {
        fn_27_C21DC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
