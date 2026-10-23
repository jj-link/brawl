#pragma force_active on
extern "C" {
void fn_27_69684(void*, short);
void __dl__FPv(void*);

void* fn_106_4554(void* p, short n) {
    if (p != 0) {
        fn_27_69684(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
