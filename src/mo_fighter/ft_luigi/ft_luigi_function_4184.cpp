#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);

extern "C" void* fn_99_4184(void* object, short deleting) {
    if (object) {
        __dt__16soHeapModuleImplFv(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
