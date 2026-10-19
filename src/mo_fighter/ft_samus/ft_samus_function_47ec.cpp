#pragma force_active on
extern "C" void* fn_94_4848(void* p, short n);
void operator delete(void* p);

extern "C" void* fn_94_47EC(void* p, short n) {
    if (p != 0) {
        fn_94_4848(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
