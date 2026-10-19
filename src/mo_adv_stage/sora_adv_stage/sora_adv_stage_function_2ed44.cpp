#pragma force_active on
extern "C" {
void fn_40_22F2C(void* self, int flag);
}

extern "C" void* fn_40_2ED44(void* p, int n) {
    if (p) {
        fn_40_22F2C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
