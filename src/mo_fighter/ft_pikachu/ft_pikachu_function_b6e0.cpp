#pragma force_active on
extern "C" void* fn_98_394C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_B6E0(void* ptr, int deleting) {
    if (ptr) {
        if (ptr) fn_98_394C(ptr, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) __dl__FPv(ptr);
    }
    return ptr;
}
