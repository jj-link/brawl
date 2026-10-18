#pragma force_active on
extern "C" void* fn_98_394C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_BBE8(void* p, int deleting) {
    if (p) {
        if (p) fn_98_394C(p, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) __dl__FPv(p);
    }
    return p;
}
