#pragma force_active on
extern "C" {
void fn_125_3BA0(void* p, short n);

void* fn_125_3B44(void* p, short n) {
    if (p != 0) {
        fn_125_3BA0(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
