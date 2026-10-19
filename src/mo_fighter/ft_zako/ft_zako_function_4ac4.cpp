#pragma force_active on
extern "C" {
void fn_27_1A75E4(void*, short);
void __dl__FPv(void*);

void* fn_126_4AC4(void* p, short flags) {
    if (p != 0) {
        fn_27_1A75E4(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
