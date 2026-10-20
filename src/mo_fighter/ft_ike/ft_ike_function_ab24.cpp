#pragma force_active on
extern "C" void* fn_119_91A4(void*, short);
void operator delete(void*);

extern "C" void* fn_119_AB24(void* p, short n) {
    if (p != 0) {
        fn_119_91A4(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
