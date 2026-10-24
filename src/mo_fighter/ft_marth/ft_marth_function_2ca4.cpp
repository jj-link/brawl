#pragma force_active on
extern "C" {
void fn_27_BED74(void*, short);
void __dl__FPv(void* p);

void* fn_106_2CA4(void* p, short n) {
    if (p != 0) {
        fn_27_BED74(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
