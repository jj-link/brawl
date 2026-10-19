#pragma force_active on
extern "C" {
void fn_88_4D64(void* p, int flag);
void __dl__FPv(void* p);

void* fn_88_4F78(void* p, int n) {
    if (p) {
        fn_88_4D64(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
