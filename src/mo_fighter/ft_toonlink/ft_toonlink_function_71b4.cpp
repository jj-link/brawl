#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_71B4(void* p, short flag) {
    if (p != 0) {
        __dt__16soStopModuleImplFv(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
