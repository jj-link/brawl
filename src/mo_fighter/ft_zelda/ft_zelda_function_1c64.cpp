#pragma force_active on
extern "C" {

void fn_104_1B48(void*, signed short);
void __dl__FPv(void*);

void* fn_104_1C64(void* a, signed short b) {
    if (a != 0) {
        fn_104_1B48(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

}
