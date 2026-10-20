#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_119_54FC(void*, short);
extern "C" void* fn_27_19A83C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_5484(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x1F4, -1);
        fn_119_54FC(static_cast<char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
