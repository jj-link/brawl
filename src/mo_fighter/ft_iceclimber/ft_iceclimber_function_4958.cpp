#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4958(void* object, short deleting) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
