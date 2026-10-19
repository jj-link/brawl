#pragma force_active on
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
void operator delete(void*);

extern "C" void* fn_121_6888(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x114, -1);
        fn_27_CBDE8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
