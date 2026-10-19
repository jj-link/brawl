#pragma force_active on
extern "C" {
void fn_27_1A383C(void* member, signed short deleteFlag);
void __dl__FPv(void* ptr);
void* fn_116_16E30(void* p, signed short deleteFlag);
}

void* fn_116_16E30(void* p, signed short deleteFlag) {
    void* r30 = p;
    if (p != 0) {
        fn_27_1A383C(p, -1);
        if (deleteFlag > 0) {
            __dl__FPv(p);
        }
    }
    return r30;
}
