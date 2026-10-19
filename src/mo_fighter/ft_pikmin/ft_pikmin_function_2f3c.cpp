#pragma force_active on
extern "C" {
void* __dt__22soControllerModuleImplFv(void*, short);
void __dl__FPv(void*);

void* fn_113_2F3C(void* object, short deleting) {
    if (object != 0) {
        __dt__22soControllerModuleImplFv(object, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
