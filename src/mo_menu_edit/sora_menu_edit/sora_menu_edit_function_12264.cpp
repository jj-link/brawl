#pragma force_active on
extern "C" {
void fn_6_1E4(void* self, int kind);
void __dl__FPv(void* p);

void* fn_5_12264(void* p, int n) {
    if (p) {
        fn_6_1E4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
