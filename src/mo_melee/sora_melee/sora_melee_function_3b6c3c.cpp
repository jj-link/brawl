#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_27_3B6C3C(void* a, int b) {
    if (a != 0 && b > 0)
        __dl__FPv(a);
    return a;
}

}
