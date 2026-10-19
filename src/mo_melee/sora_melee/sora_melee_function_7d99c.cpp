#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7D99C(void* p, int deleting) {
    if (p != 0 && deleting > 0)
        __dl__FPv(p);
    return p;
}
