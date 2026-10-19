#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_566C(void* object, short shouldDelete) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
