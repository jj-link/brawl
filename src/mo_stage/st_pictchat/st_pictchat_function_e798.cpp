#pragma force_active on
extern "C" {
void fn_73_2CC8(void*, int);

void* fn_73_E798(void* p, int n) {
    if (p != 0) {
        fn_73_2CC8(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
