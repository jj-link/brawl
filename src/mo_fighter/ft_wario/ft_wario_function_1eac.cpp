#pragma force_active on
extern "C" {
void* fn_110_1F08(void* p, short n);
void operator delete(void* p);

void* fn_110_1EAC(void* p, short n) {
    if (p != 0) {
        fn_110_1F08(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
