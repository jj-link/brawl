#pragma force_active on
extern "C" {
void* fn_63_A9D0(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
