#pragma force_active on
extern "C" {
void fn_800726A8(void* p, int flag);

void* fn_90_3AC(void* p, int n) {
    if (p != 0) {
        fn_800726A8(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
