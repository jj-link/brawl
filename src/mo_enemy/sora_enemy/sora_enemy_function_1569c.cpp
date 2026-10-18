#pragma force_active on
struct fn_41_1569C_T { int m; };

extern "C" fn_41_1569C_T* fn_41_1569C(fn_41_1569C_T* p, short n) {
    if (p != 0) {
        if (n > 0) {
            delete p;
        }
    }
    return p;
}
