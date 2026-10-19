#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_5A38(void* object, short flags) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, static_cast<short>(-1));
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
