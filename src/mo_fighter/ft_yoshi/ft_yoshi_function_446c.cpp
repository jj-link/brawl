#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_446C(void* object, short deleting) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
