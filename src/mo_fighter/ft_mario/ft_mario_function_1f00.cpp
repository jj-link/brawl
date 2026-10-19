#pragma force_active on
extern "C" {
void* __dt__16soHeapModuleImplFv(void*, short);

void* fn_91_1F00(void* object, short deleting) {
    if (object != 0) {
        __dt__16soHeapModuleImplFv(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
