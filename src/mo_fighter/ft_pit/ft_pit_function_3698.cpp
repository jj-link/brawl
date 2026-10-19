#pragma force_active on
extern "C" void* fn_27_63EBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_112_3698(void* p, short flag) {
    if (p != 0) {
        fn_27_63EBC(p, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
