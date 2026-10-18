#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_4788(void* object, short flag) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
