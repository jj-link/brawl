#pragma force_active on
extern "C" {
extern void* fn_106_4AA0(void*, short);
extern void __dl__FPv(void*);

void* fn_106_4A44(void* p, short n) {
    if (p != 0) {
        fn_106_4AA0(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
