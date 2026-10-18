#pragma force_active on
extern "C" void* fn_98_394C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_BA50(void* p, int deleting) {
    if (p) {
        if (p) fn_98_394C(p, (short)0);
        if ((short)deleting > 0) __dl__FPv(p);
    }
    return p;
}
