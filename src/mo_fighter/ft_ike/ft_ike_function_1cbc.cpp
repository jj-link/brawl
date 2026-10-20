#pragma force_active on
extern "C" {
void fn_119_1B44(void*, short);
void __dl__FPv(void*);

void* fn_119_1CBC(void* p, short del) {
    if (p != 0) {
        fn_119_1B44(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
