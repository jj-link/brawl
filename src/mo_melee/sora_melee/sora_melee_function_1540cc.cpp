#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1540CC(void* object, short flag) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
