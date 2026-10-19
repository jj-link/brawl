#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_27_3A1F8C(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
