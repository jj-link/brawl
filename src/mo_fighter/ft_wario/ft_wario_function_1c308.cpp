#pragma force_active on
extern "C" {
void* fn_110_1C308(void* p, short n) {
    if (p != 0 && n > 0) {
        ::operator delete(p);
    }
    return p;
}
}
