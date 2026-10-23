#pragma force_active on
extern "C" {
void fn_27_7700(void*, short);
void __dl__FPv(void*);

void* fn_106_1EE4(void* p, short n) {
    if (p != 0) {
        fn_27_7700(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
