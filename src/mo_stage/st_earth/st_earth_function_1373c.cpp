#pragma force_active on
extern "C" {
void fn_66_2C60(void* p, int flags);
}

extern "C" void* fn_66_1373C(void* p, int n) {
    if (p != 0) {
        fn_66_2C60(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
