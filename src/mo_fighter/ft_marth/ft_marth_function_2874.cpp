#pragma force_active on
extern "C" {
void fn_27_1A61E0(void*, short);
void __dl__FPv(void*);
void* fn_106_2874(void* p, short n) {
    if (p != 0) {
        fn_27_1A61E0(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}