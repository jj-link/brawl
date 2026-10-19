#pragma force_active on
extern "C" {
void fn_94_4BB4(void*, short);
void __dl__FPv(void*);

void* fn_94_1CA28(void* p, short n) {
    if (p != 0) {
        fn_94_4BB4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
