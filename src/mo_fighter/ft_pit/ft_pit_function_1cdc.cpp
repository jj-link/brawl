#pragma force_active on
extern "C" {
void fn_112_1B64(void* p, short flag);
void __dl__FPv(void* p);

void* fn_112_1CDC(void* p, short flag) {
    if (p != 0) {
        fn_112_1B64(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
