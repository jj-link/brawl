#pragma force_active on
extern "C" void fn_51_289C(void* p, int arg);

void operator delete(void* p);

extern "C" void* fn_51_3C30(void* p, int flag) {
    if (p != 0) {
        fn_51_289C(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
