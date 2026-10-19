#pragma force_active on
extern "C" {
void* __dt__22soControllerModuleImplFv(void*, short);
void __dl__FPv(void*);

void* fn_104_11FD8(void* p, short flag) {
    if (p) {
        __dt__22soControllerModuleImplFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
