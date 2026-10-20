#pragma force_active on
extern "C" {
void fn_27_241EA4(void* a1, int a2);
void __dl__FPv(void* p);

void* fn_27_256980(void* p, int flag) {
    if (p) {
        fn_27_241EA4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
