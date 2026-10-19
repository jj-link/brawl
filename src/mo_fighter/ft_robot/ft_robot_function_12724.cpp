#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_120_12724(void* p1, short p2) {
    if (p1 != 0) {
        __dt__16soStopModuleImplFv(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
