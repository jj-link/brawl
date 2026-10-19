#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_4918(void* object, short deleting) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
