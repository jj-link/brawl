#pragma force_active on
struct fn_41_1569C_T;

extern "C" fn_41_1569C_T* fn_41_1569C(fn_41_1569C_T* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" fn_41_1569C_T* fn_41_15640(fn_41_1569C_T* p, short n) {
    if (p != 0) {
        fn_41_1569C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
