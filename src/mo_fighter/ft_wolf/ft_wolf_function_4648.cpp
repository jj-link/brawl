#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_4648(void* p, short flag) {
    if (p != 0) {
        __dt__16soHeapModuleImplFv(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
