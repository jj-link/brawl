#pragma force_active on
extern "C" {
void* fn_126_2F90(void* p, short n);
}

void operator delete(void* p);

extern "C" void* fn_126_2F34(void* p, short n) {
    if (p != 0) {
        fn_126_2F90(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
