#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_4684(void* object, int shouldDelete) {
    if (object != 0) {
        __dt__16soStopModuleImplFv(object, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
