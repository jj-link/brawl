#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" {

void* fn_105_1E2C(void* a, short b) {
    if (a != 0 && b > 0) {
        __dl__FPv(a);
    }
    return a;
}

}
