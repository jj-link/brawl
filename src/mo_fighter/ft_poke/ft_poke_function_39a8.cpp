#pragma force_active on
extern "C" {
void* fn_27_63EBC(void*, short);
void __dl__FPv(void*);

void* fn_116_39A8(void* p, short del) {
    if (p != 0) {
        fn_27_63EBC(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
