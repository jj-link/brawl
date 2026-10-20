#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_118_4614(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_6A14(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, -1);
        if (object != 0) {
            fn_118_4614(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
