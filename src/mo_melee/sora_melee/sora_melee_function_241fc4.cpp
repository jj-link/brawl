#pragma force_active on
extern "C" {
void fn_27_241EA4(void* a1, int a2);
void __dl__FPv(void* ptr);

void* fn_27_241FC4(void* a1, int a2) {
    if (a1 != 0) {
        fn_27_241EA4(a1, 0);
        if (a2 > 0) {
            __dl__FPv(a1);
        }
    }
    return a1;
}
}
