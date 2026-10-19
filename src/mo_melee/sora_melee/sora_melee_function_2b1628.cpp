#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_27_2B1628(void* p, int flag) {
    if (p != 0) {
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
