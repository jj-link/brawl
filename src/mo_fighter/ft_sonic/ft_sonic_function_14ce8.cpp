#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* __dt__22soControllerModuleImplFv(void*, short);
}

extern "C" {
void* fn_123_14CE8(void* p1, short p2) {
    if (p1 != 0) {
        __dt__22soControllerModuleImplFv(p1, static_cast<short>(0));
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
