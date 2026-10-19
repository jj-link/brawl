#pragma force_active on
extern "C" void* fn_122_1DF8(void* p, short flag);
void operator delete(void* p);

extern "C" void* fn_122_1D9C(void* p, short flag) {
    if (p != 0) {
        fn_122_1DF8(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
