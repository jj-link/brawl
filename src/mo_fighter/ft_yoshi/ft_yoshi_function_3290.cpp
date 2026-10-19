#pragma force_active on
extern "C" {
void* fn_27_19874C(void*, short);
void __dl__FPv(void*);

void* fn_95_3290(void* p, short flag) {
    if (p != 0) {
        fn_27_19874C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
