#pragma force_active on
extern "C" {
void* fn_27_384F94(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
