#pragma force_active on
extern "C" {
void* fn_27_3544C(void*, short);
void __dl__FPv(void*);

void* fn_94_4BF4(void* p, short flags) {
    if (p != 0) {
        fn_27_3544C(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
