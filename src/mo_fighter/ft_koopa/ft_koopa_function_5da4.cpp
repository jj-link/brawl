#pragma force_active on
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_102_5E1C(void*, short);
extern "C" void* fn_27_19A83C(void*, short);
void operator delete(void*);

extern "C" void* fn_102_5DA4(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x1F4, -1);
        fn_102_5E1C(static_cast<char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
